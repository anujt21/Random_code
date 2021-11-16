class Node:
    def __init__(self,char):
        self.char=char
        self.next=None
        self.prev=None
    
    def print_node(self):
        print(self.char)
        
    def __str__(self):
        vals = []
        objs = set()
        curr = self
        while curr is not None:
            curr_str = str(curr.char)
            if curr in objs:
                vals.append("{} -> ... (to infinity and beyond)".format(curr_str))
                break
            else:
                vals.append(curr_str)
                objs.add(curr)
            curr = curr.next

        return " -> ".join(vals)



def print_tracks(track_map):
    for track in track_map:
        head=track
        tmp_str=""
        while head!=None:
            tmp_str=head.char+tmp_str
            head=head.next
        print(tmp_str,end='')
        print("\n")
    

def move(from_track,to_track,count,track_list):
    ##incrementing count to include T
    count+=1
    
    track1=track_list[from_track-1]
    track2=track_list[to_track - 1]
    
    ##Check if moving conditions are met
    if track2.char=='T' or track1.char!='T':
        print("Invalid command")
        return track_list
    
    ##asserts that there is enough space. Also asserts that there is at least 1 space
    space=0
    
    ##Gets the first node in track2 which is empty
    init_empty=None
    
    tmp=track2
    
    while tmp!=None:
        if tmp.char=='-':
            if init_empty==None:
                init_empty=tmp
            space=space+1
        tmp=tmp.next

    
    if count>space:
        print("Invalid command")
        return track_list
    
    cur1=track1
    tmp1=cur1
    ##track1=track1.next
    
    tmp_count=1
    
    while tmp_count!=count:
        tmp1=tmp1.next
        ##track1=track1.next
        tmp_count+=1
    track1=tmp1.next
    tmp1.next=None
    
    print(f"{track1}")
    print(f"{cur1}")
    
    tmp=init_empty
    if count>1:
        for i in range(count-1):
            tmp=tmp.next
    if init_empty.prev!=None:
        init_empty.prev.next=tmp.next
    
    tmp1.next=track2
    tmp.next=None
    track2=cur1
    
    tmp=track1
    while tmp.next!=None:
        tmp=tmp.next
    tmp.next=init_empty
    
    track_list[from_track-1]=track1
    track_list[to_track - 1]=track2
    
    return track_list
    

    

def main():
    
    infile=open("yard1.txt")
    
    track_map=[]
    track_list=[]
    
    for line in infile:
        track_map.append(list(line))
    
    loco_count=0
    dest_arr=[]
    
    for track in track_map:
        
        ##Removing the extra '-'
        track.pop()
        if track[-1]=='-':
            track.pop()
        track.pop(0)
        
        i=-1
        while 1:
            try:
                ##Finds loco and dest count
                if (track[i] not in dest_arr) and track[i]!='T' and track[i]!='-':
                    dest_arr.append(track[i])
                if track[i]=='T':
                    loco_count=loco_count+1
                    
                ##Creates objects
                track[i]=Node(track[i])

                i=i-1
            except IndexError:
                break
        i=-1
        
        while 1:
            try:
                ##Links the objects
                track[i].next=track[i-1]
                
                if i!=-1:
                    track[i].prev=track[i+1]
                i=i-1
            except IndexError:
                break
        track_list.append(track[-1])

    
    
    print_tracks(track_list)
    print("Locomotive count: "+str(loco_count))
    print("Destination Count: "+str(len(dest_arr)))
    
    
    inp_str=input("What is your command?\n")
    inp_arr=[]
    inp_arr=inp_str.split(" ")
    move(int(inp_arr[2]),int(inp_arr[3]),int(inp_arr[1]),track_list)
    
    
    
    print_tracks(track_list)
    
    
    
main()