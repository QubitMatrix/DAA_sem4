s=input().split()
arr=[(x,y) for x,y in enumerate (list(map(int,s)))]
print(arr)
for i in range(len(arr)-1):
    minpos=i
    for j in range(i+1,len(arr)):
        if(arr[minpos][1]>arr[j][1]):
            minpos=j
    t=arr[0:i]
    t.append(arr[minpos])
    arr[i+1:]=arr[i:minpos]+arr[minpos+1:]
    arr[:i+1]=t
print(arr)

