import sys

N,M,V = map(int,sys.stdin.readline().split())

#경로가 담긴 v
v=[[] for i in range (N+1)]

#입력받아서 2차원벡터 v를 만든다
for i in range(M):
    v1,v2=map(int,sys.stdin.readline().split())
    v[v1].append(v2)
    v[v2].append(v1)

#0~N까지 check 생성
check=[False for i in range(N+1)]

#dfs
def dfs(now):
    check[now] = True
    sys.stdout.write(str(now)+' ')

    #다음위치를 본다
    for i in v[now]:
        if check[i]==False:
            dfs(i)

#v를 정렬
for i in range(N+1):
    v[i].sort()
    
dfs(V)
sys.stdout.write('\n')

for i in range(N+1):
    check[i] = False

#bfs
#정렬필요


q=[V]
check[V]=True

while len(q)>0:
    now = q[0]
    sys.stdout.write(str(now)+' ')
    q.pop(0)

    #다음위치를 본다
    for i in v[now]:
        if check[i]==False:
            check[i] = True
            q.append(i)

