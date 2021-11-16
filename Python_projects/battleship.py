import os

class Board:
    def __init__(self,size):
        assert size>0
        self.board_map=[]
        endline='+'
        for _ in range(size):
            endline=endline+'--'
        endline+='-+'
        line='|'
        for _ in range(size):
            line+=' .'
        line+=' |'
        self.board_map.append(endline)
        for _ in range(size):
            self.board_map.append(line)
        self.board_map.append(endline)
        
    
    def add_ship(self,ship):
        size=len(self.board_map)-2
        while 1:
            try:
                print('Enter position of the '+ship.Name+':\n')
                temp=input().split(',')
                pos=(int(temp[0]),int(temp[1]))
                
                assert pos[0]>=0 and pos[0]<size and pos[1]>=0 and pos[1]<size
                new_shape=[]
                for i in range(len(ship.ship_shape)):
                    temp=(pos[0]+ship.ship_shape[i][0],pos[1]+ship.ship_shape[i][1])
                    assert self.board_map[size-temp[1]][2+2*temp[0]]=='.'
                    new_shape.append(temp)
                    
                ship.ship_shape=new_shape
                for ship_pos in ship.ship_shape:
                    assert ship_pos[0]>=0 and ship_pos[0]<size and ship_pos[1]>=0 and ship_pos[1]<size
                    
                
                break
            except:
                print('Please enter an appropriate position')
                
        
        for ship_pos in ship.ship_shape:
            temp=self.board_map[size-ship_pos[1]].split()
            temp[1+ship_pos[0]]=ship.initial
            self.board_map[size-ship_pos[1]]=' '.join(temp)
        
    
    def boardPrint(self):
        
        if len(self.board_map)-2<=10:
            print('  '+self.board_map[0])
            for i in range(len(self.board_map)-2):
                print(str(len(self.board_map)-i-3)+' '+self.board_map[i+1])
            print('  '+self.board_map[len(self.board_map)-1])
            endline='   '
            for i in range(len(self.board_map)-2):
                endline+=(' '+str(i))
            print(endline)
        else:
            print('   '+self.board_map[0])
            for i in range(len(self.board_map)-2):
                print(str(len(self.board_map)-i-3).rjust(2)+' '+self.board_map[i+1])
            print('   '+self.board_map[len(self.board_map)-1])
            endline='    '
            for i in range(10):
                endline+='  '
            for i in range(10,len(self.board_map)-2):
                endline+=(' '+str(int(i/10)))
            print(endline)
            endline='    '
            for i in range(len(self.board_map)-2):
                endline+=(' '+str(i%10))
            print(endline)
    
    def has_been_used(self,position):
        size=len(self.board_map)-2
        if self.board_map[size-position[1]][2+2*position[0]] in '.CBSD':
            return 0
        else:
            return 1

    
    def attempt_move(self,position,user_state,ship_list):
        #user_state 1 for the user and -1 for enemy
        size=len(self.board_map)-2
        assert self.has_been_used(position)==0
        if user_state==1:
            print('Is it a hit?(y/n)')
            inp=input()
            if inp=='n':
                temp=self.board_map[size-position[1]].split()
                temp[1+position[0]]='o'
                self.board_map[size-position[1]]=' '.join(temp)
                return 0
            elif inp=='y':
                temp=self.board_map[size-position[1]].split()
                temp[1+position[0]]='*'
                self.board_map[size-position[1]]=' '.join(temp)
                return 1
        elif user_state==-1:
            if self.board_map[size-position[1]][2+2*position[0]]=='.':
                print('It is a miss')
                temp=self.board_map[size-position[1]].split()
                temp[1+position[0]]='o'
                self.board_map[size-position[1]]=' '.join(temp)
                return 0
            else:
                print('It is a hit')
                temp=self.board_map[size-position[1]].split()
                temp[1+position[0]]='*'
                self.board_map[size-position[1]]=' '.join(temp)
                
                for ship in ship_list:
                    if position in ship.ship_shape:
                        if ship.is_sunk(self)==1:
                            for position in ship.ship_shape:
                                temp=self.board_map[size-position[1]].split()
                                temp[1+position[0]]='X'
                                self.board_map[size-position[1]]=' '.join(temp)
                        break
                return 1
    

class Ship:
    def __init__(self,name,shape,shiptype):
        self.Name=name
        self.initial=self.Name[0]
        self.ship_shape=[]
        if shiptype==1:
            for i in range(shape):
                self.ship_shape.append((i,0))
        elif shiptype==2:
            self.ship_shape.append((0,0))
            temp=[]
            print('First coordinate of the ship is (0,0). Enter '+str(shape-1)+' more connected coordinates to complete the ship.')
            
            for _ in range(shape-1):
                while 1:
                    temp=input()
                    temp=temp.split(',')
                    pos=(int(temp[0]),int(temp[1]))
                    b=connected_check(pos,self.ship_shape)
                    if b==1:
                        break
                    else:
                        print('Enter an appropriate coordinate')
                    
                self.ship_shape.append((pos[0],pos[1]))
    
    def ship_print(self):
        print(self.ship_shape)
    
    def is_sunk(self,board):
        size=len(board.board_map)-2
        for position in self.ship_shape:
            if board.board_map[size-position[1]][2+2*position[0]]!='*':
                return 0
            
        return 1
    
    def rotate(self,amount):
        assert amount in '0123'
        amount=int(amount)
        if amount==0:
            pass
        elif amount==1:
            new_shape=[]
            for pos in self.ship_shape:
                new_shape.append((pos[1],-pos[0]))
            self.ship_shape=new_shape
        elif amount==2:
            new_shape=[]
            for pos in self.ship_shape:
                new_shape.append((-pos[0],-pos[1]))
            self.ship_shape=new_shape
        elif amount==3:
            new_shape=[]
            for pos in self.ship_shape:
                new_shape.append((-pos[1],pos[0]))
            self.ship_shape=new_shape


def build_ship(name,shape,shiptype):
    temp=Ship(name,shape,shiptype)
    
    print('Current shape of '+name+':')
    temp.ship_print()
    
    print('Do you want to rotate the ship clockwise? (0 for no rotation, 1 for 90, 2 for 180, and 3 for 270.')
    amt=input()
    temp.rotate(amt)
    temp.ship_print()
    
    return temp
    
def connected_check(pos,list):
    if pos in list:
        return 0

    for p in list:
        if p[0]==pos[0]:
            if abs(p[1]-pos[1]):
                return 1
        if p[1]==pos[1]:
            if abs(p[0]-pos[0])==1:
                return 1
    return 0

def user_continue():
    input('Press [Enter] to continue')
    print('\n')
    os.system('cls')

def main():
    user_board=Board(10)
    enemy_board=Board(10)
    
    print('Do you want 1. default ships or 2. custom made ships')
    ship_type=int(input())
    
    print('Select the shape and position of the ships:')
    ship_list=[]
    
    user_continue()
    ship_list.append(build_ship('Carrier',5,ship_type))
    user_board.add_ship(ship_list[-1])
    user_board.boardPrint()
    
    user_continue()
    ship_list.append(build_ship('Battleship',4,ship_type))
    user_board.add_ship(ship_list[-1])
    user_board.boardPrint()
    
    user_continue()
    ship_list.append(build_ship('Cruiser',3,ship_type))
    user_board.add_ship(ship_list[-1])
    user_board.boardPrint()
    
    user_continue()
    ship_list.append(build_ship('Submarine',3,ship_type))
    user_board.add_ship(ship_list[-1])
    user_board.boardPrint()
    
    user_continue()
    ship_list.append(build_ship('Destroyer',2,ship_type))
    user_board.add_ship(ship_list[-1])
    user_board.boardPrint()
    
    print('Are you the first to play?(y/n)')
    inp=input()
    while 1:
        try:
            if inp=='y' or inp=='n':
                break
        except:
            print('Please enter an appropriate response')
    
    user_hits=0
    enemy_hits=0
    
    if inp=='y':
        while user_hits!=17 and enemy_hits!=17:
            print('Where do you want to fire?')
            temp=input().split(',')
            pos=(int(temp[0]),int(temp[1]))
            enemy_hits+=enemy_board.attempt_move(pos,1,ship_list)
            print(enemy_board.boardPrint())
            
            
            print('Where did the enemy shoot?')
            temp=input().split(',')
            pos=(int(temp[0]),int(temp[1]))
            while 1:
                if user_board.has_been_used(pos)==0:
                    break
                print('Enter an appropriate position')
            temp=input().split(',')
            pos=(int(temp[0]),int(temp[1]))
            user_hits+=user_board.attempt_move(pos,-1,ship_list)                    
            print(user_board.boardPrint())
    elif inp=='n':
        while user_hits!=17 and enemy_hits!=17:
            print('Where did the enemy shoot?')
            temp=input().split(',')
            pos=(int(temp[0]),int(temp[1]))
            while 1:
                if user_board.has_been_used(pos)==0:
                    break
                print('Enter an appropriate position')
            temp=input().split(',')
            pos=(int(temp[0]),int(temp[1]))
            user_hits+=user_board.attempt_move(pos,-1,ship_list)                    
            print(user_board.boardPrint())
            
            print('Where do you want to fire?')
            temp=input().split(',')
            pos=(int(temp[0]),int(temp[1]))
            enemy_hits+=enemy_board.attempt_move(pos,1,ship_list)
            print(enemy_board.boardPrint())
        
    


main()