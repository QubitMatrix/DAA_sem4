from collections import defaultdict
def bcst_create(pattern):
    bcst=defaultdict(int)
    for x in range(0,len(pattern)-1):
        bcst[pattern[x]]=len(pattern)-x-1
    return bcst
def gsst_create(pattern):
    gsst=defaultdict(int)
    r2=0
    count=0
    for x in range(1,len(pattern)+1):
        count=0
        r2=0
        suffix=pattern[-1*x:]#last x characters
        mis_char=pattern[-1*x-1] if (-1*x-1)>=-1*len(pattern) else "~" #character before suffix
        rev_pattern=pattern[0:-1][::-1] #reverse pattern to find rightmost occurance
        rev_suffix=suffix[::-1] #reverse suffix
        while(True):
            pos=rev_pattern.find(rev_suffix)#get rightmost occurance
            if(pos==-1):#R2 if not found
                r2=1
                break
            check_char=rev_pattern[pos+x] if pos+x<len(rev_pattern) else "`" #character before the occurance
            if(check_char!=mis_char):#R1
                gsst[x]=pos+count+1
                break
            rev_pattern=rev_pattern[pos+1:]#truncate to check for next rightmost
            count+=pos+1 #add distance

        if(r2):#R2
            prefix=rev_pattern[::-1]
            while(True):
                if(len(suffix)==1):#no occurance of even smaller suffixes
                    gsst[x]=len(pattern)
                    break
                suffix=suffix[1:]#decrease length of suffix by one
                if(prefix.startswith(suffix)):
                    gsst[x]=len(pattern)-len(suffix)
                    break
    return gsst
def boyer_moore(text,pattern,bcst,gsst):
    pos=len(pattern)-1
    match=0
    occurance=0
    d1=d2=d=0
    comparisons=0
    while(pos<len(text)):
        end=pos
        for x in range(len(pattern)-1,-1,-1):
            comparisons+=1
            if(text[pos]==pattern[x]):
                match+=1
                pos-=1
            else:
                if(text[pos] in bcst):
                    d1=max(bcst[text[pos]]-match,1)
                else:
                    d1=len(pattern)-match
                if(match!=0):
                    d2=gsst[match]
                d=max(d1,d2)
                pos=end+d
                match=0
                d1=0
                d2=0
                break
        if(match==len(pattern)):
            print("occurance at",end-len(pattern)+1)
            d=gsst[match]
            pos=end+d
            match=0
            occurance+=1
    print("No of occurances=",occurance,"\nNo of comparisons=",comparisons)
text=input()
pattern=input()
bcst=bcst_create(pattern)
print("bad character shift table:\n",bcst)
gsst=gsst_create(pattern)
print("good suffix shift table:\n",gsst)
boyer_moore(text,pattern,bcst,gsst)
