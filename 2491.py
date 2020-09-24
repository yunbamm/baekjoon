import sys

N = int(sys.stdin.readline())

pre = 0
small =int(0)
big = int(0)
max_small=int(small)
max_big =int(big)
arr=[]

#입력받기
arr = sys.stdin.readline().split()

#arr를 돌면서 확인
for i in arr:
    now = int(i)

    #현재값이 전꺼보다 크면?
    if now > pre:
        big+=1
        small=1
    #현재값이 전꺼보다 작으면?
    if now < pre:
        small+=1
        big=1
    #같으면
    if now==pre:
        small+=1
        big+=1

    max_small = max(small,max_small)
    max_big = max(big,max_big)

    #pre update
    pre = now

answer = max(max_small , max_big)
sys.stdout.write(str(answer))

