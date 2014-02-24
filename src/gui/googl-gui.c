#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
   GtkWidget *short_url_entry;
   GtkWidget *long_url_entry;
} __entries;

static void shortern_url(GtkButton *, __entries *);
static void copy_url(GtkButton *, __entries *);
static void handle_error(GError *error);

int main(int argc, char ** argv)
{
   GtkWidget *label, *window, *button, * vbox, * hbox;
   __entries *entries;
   
   gtk_init(&argc, &argv);


   entries  = g_malloc(sizeof(__entries));
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(window), "Goo.gl URL Shortener");
   gtk_container_set_border_width(GTK_CONTAINER(window), 20);
   gtk_widget_set_size_request(window, 500, 160);
  
   g_signal_connect(G_OBJECT(window), "destroy",
		    G_CALLBACK(gtk_main_quit), NULL);


   vbox = gtk_vbox_new(FALSE, 0); // Box to contain widgets

   // Opening logo
   label = gtk_label_new("GOO.GL");
   gtk_box_pack_start(GTK_BOX(vbox), label,FALSE,FALSE,4);

   // Adding first label
   label = gtk_label_new("Enter Long URL");
   gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

   // Box to hold entry
   hbox = gtk_hbox_new(FALSE, 0);
   
   /* entry for long URL */
   entries->long_url_entry = gtk_entry_new();
   button = gtk_button_new_with_mnemonic ("_Shorten URL");

   g_signal_connect(G_OBJECT(button), "clicked",
		    G_CALLBACK(shortern_url),
		    (gpointer) entries);

   gtk_box_pack_start(GTK_BOX(hbox), entries->long_url_entry,TRUE, TRUE,5);
   gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, TRUE, 0);

   // Adding hbox to the main Vbox
   gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);

   label = gtk_label_new("Short URL Below");
   gtk_box_pack_start(GTK_BOX(vbox),label, FALSE,FALSE, 0);
   
   /* Entry for short URL */
   entries->short_url_entry = gtk_entry_new();
   gtk_entry_set_editable(GTK_ENTRY(entries->short_url_entry), FALSE);
   
    button = gtk_button_new_from_stock(GTK_STOCK_COPY);

   g_signal_connect(G_OBJECT(button), "clicked",
		    G_CALLBACK(copy_url), (gpointer) entries);
   
   hbox = gtk_hbox_new(FALSE,1);
   gtk_box_pack_start(GTK_BOX(hbox), entries->short_url_entry, TRUE,TRUE, 0);
   gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 0);

   // Adding hbox to the main Vbox
   gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);

  
   gtk_container_add(GTK_CONTAINER(window), vbox);
   gtk_widget_show_all(window);

   gtk_main();

   return 0;
}


static void shortern_url(GtkButton * button, __entries *entries)
{
   gchar * filename, *content;
   GIOChannel  *read;
   GError *error=NULL;

   gsize bytes;

   /* Build a filename in the user's temp directory */
   filename = g_build_filename(g_get_tmp_dir(), "googl-gui", NULL);
   
   pid_t pid;
   pid = fork();

   switch((int)pid)
   {
   case -1:
      g_print("Child process could not be created\n");
      exit(EXIT_FAILURE);

   case 0:
      remove(filename);
      gchar *URL;
      URL = gtk_entry_get_text(GTK_ENTRY(entries->long_url_entry));
      execlp("/usr/bin/googl"," ","-f", filename,URL,  NULL);

   default:
      // Parent waits untill child is complete
      wait(NULL);
      
      /* Check if file was  was created */
      if(g_file_test(filename, G_FILE_TEST_EXISTS))
      {
	 /* Get the contents of the temporary file and report any errors */
	 read = g_io_channel_new_file(filename, "r", &error);
	 handle_error(error);
	 g_io_channel_read_to_end(read, &content, &bytes, NULL);
	 g_io_channel_shutdown(read, TRUE, &error);
      } else {
	 content=malloc(sizeof( strlen("Wrong URL")));
	 strcpy(content, "Wrong URL");
      }
     
      gtk_entry_set_text(GTK_ENTRY(entries->short_url_entry), content);
      g_free(content);
      g_free(filename);
   }
}

static void handle_error(GError *error)
{
   if (error != NULL)
   {
      g_print(error->message);
      g_clear_error(&error);
   }
}

static void copy_url(GtkButton *button, __entries *entries)
{
   GtkClipboard *  my_clipboard;
   const gchar  * clipboard_text;
   
   my_clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD );
   clipboard_text = gtk_entry_get_text(GTK_ENTRY(entries->short_url_entry));

   gtk_clipboard_set_text (my_clipboard,clipboard_text, -1);
   g_print("Copy URL Clicked\n");
}
