{ version ? "0", revision ? "local" }:

with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "googl";

  src = ./.;

  phases = [ "installPhase" ];

  installPhase = ''
    make PREFIX=$out install
  '';
}
