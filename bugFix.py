from math import factorial as fc

def ncr(n,r):
    return fc(n)//(fc(n-r)*fc(r))

# def combination(n,r):
#     temp = n - r
#     if temp < r:
#         r = temp
#     res = 1
#     for i in range(r):
#         res *= n
#         n-=1
#     return res//r
    
    
t = int(input().rstrip())
for _ in range(t):
    N, K = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    last_element = a[K-1]
    total = a.count(last_element)
    cnt = 0
    for i in range(K):
        if a[i] == last_element:
            cnt+=1
    print(ncr(total,cnt))
