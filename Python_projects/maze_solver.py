import sys

def print_maze(list):
    for _ in list:
        for node in _:
            print(node.node_char,end='')
    print('\n')

class Node:
    def __init__(self,pos,char):
        self.pos=pos
        self.node_char=char
        self.parent=None
        self.children=[]
        
    def print_children(self):
        for child in self.children:
            print(child.pos)

def connect_maze(list,root):
    i=root[0]
    j=root[1]
    n=0
    s=0
    e=0
    w=0
    
    if i+1<len(list):
        try:
            if list[i+1][j].node_char in '#E' and list[i][j].parent!=list[i+1][j]:
                list[i][j].children.append(list[i+1][j])
                list[i+1][j].parent=list[i][j]         
                n=1
        except IndexError:
            pass
            
    
    if i-1>=0:
        try:
            if list[i-1][j].node_char in '#E' and list[i][j].parent!=list[i-1][j]:
                list[i][j].children.append(list[i-1][j])
                list[i-1][j].parent=list[i][j]           
                s=1
        except IndexError:
            pass
            
    
    if j+1<len(list[i]):
        try:
            if list[i][j+1].node_char in '#E' and list[i][j].parent!=list[i][j+1]:
                list[i][j].children.append(list[i][j+1])
                list[i][j+1].parent=list[i][j]
                e=1
        except IndexError:
            pass
            
            
    if j-1>=0:
        try:
            if list[i][j-1].node_char in '#E' and list[i][j].parent!=list[i][j-1]:
                list[i][j].children.append(list[i][j-1])
                list[i][j-1].parent=list[i][j]
                w=1
        except IndexError:
            pass
    
    if n==1:
        connect_maze(list,(i+1,j))
    if s==1:
        connect_maze(list,(i-1,j))
    if e==1:
        connect_maze(list,(i,j+1))
    if w==1:
        connect_maze(list,(i,j-1))
    
def find_path(list,start,path):
    for child in list[start[0]][start[1]].children:
        if child.node_char=='E':
            return path
    
    if list[start[0]][start[1]].children==[]:
        return None
    else:
        for child in list[start[0]][start[1]].children:
            path.append(child.pos)
            tmp_path=find_path(list,coord_index(list,child.pos,None),path)
            if tmp_path==None:
                path.pop()
                pass
            else:
                path=tmp_path
                return path
    
    return None

def coord_index(list,pos,index):
    if pos==None:
        pos=(index[1],len(list)-index[0]-1)
        return pos
    elif index==None:
        index=(len(list)-pos[1]-1,pos[0])
        return index
    

def main():
    
    infile=open("maze_testcase.txt")
    
    maze_map=[]
    
    for line in infile:
        maze_map.append(list(line))
    
    for i in range(len(maze_map)):
        for j in range(len(maze_map[i])):
            if maze_map[i][j]=='S':
                start_index=(i,j)
                
            maze_map[i][j]=Node((j,len(maze_map)-i-1),maze_map[i][j])
            
    connect_maze(maze_map,start_index)
    sol_path=find_path(maze_map,start_index,[])

    
    for pos in sol_path:
        index=coord_index(maze_map, pos, None)
        maze_map[index[0]][index[1]].node_char='.'
    
    print_maze(maze_map)

        

main()