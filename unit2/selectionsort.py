s=input().split()
arr=[(x,y) for x,y in enumerate (list(map(int,s)))]
print(arr)
for i in range(len(arr)-1):
    minpos=i
    for j in range(i+1,len(arr)):
        if(arr[minpos][1]>arr[j][1]):
            minpos=j
    arr[minpos],arr[i]=arr[i],arr[minpos]
print(arr)

