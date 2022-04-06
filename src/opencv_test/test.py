from ast import If


def sort(a):
    for i in range(0,len(a)-1):
        for j in range(0,len(a)-1):
            if a[j]>a[j+1]:
                change = a[j]
                a[j] = a[j+1]
                a[j+1] = change
    print(a)
    
sort([3,2,7,4,6,7,5,1])
            
        