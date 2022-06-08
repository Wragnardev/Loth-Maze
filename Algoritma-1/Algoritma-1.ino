//0=left 1=forward 2=right 3=backward
int yon=0;
int x=9;
int y=0;
//ön 6 sol 5 sağ 4 arka sağ 3 arka sol 2 
int maze[ 17 ][ 14 ] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

int leftSensor;
int rightSensor;
int forwardSensor;

void left (){
  if(yon==0){
    yon=3;
  }else{
    yon-=1;
  }
}

void right (){
  if(yon==3){
    yon=0;
  }else{
    yon+=1;
  }
}

void back (){
  right();
  right();
}

void forward(){
  if(yon==0){
    x-=1;
  }else if(yon==1){
    y+=1;
  }else if(yon==2){
    x+=1;
  }else{
    y-=1;
  }
}








void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
}

void loop() {
  leftSensor=digitalRead(5);
  forwardSensor=digitalRead(6);
  rightSensor=digitalRead(2);
  Serial.println(rightSensor);
  maze[x][y]=1;
  if(yon==0){
    if(rightSensor==1 && maze[x][y+1]==0){
      right();
      forward();
    }
    else if(forwardSensor==1 && maze[x-1][y]==0){
      forward();
    }
    else if(leftSensor==1 && maze[x][y-1]==0){
      left();
      forward();
    }
    else if(maze[x+1][y]==0){
      back();
    }
    else if(rightSensor==1){
      right();
      forward();
    }
    else if(forwardSensor==1){
      forward();
    }
    else if(leftSensor==1){
      left();
      forward();
    }
    else{
      back();
    }
  }
  else if(yon==1){
    if(forwardSensor==1 && maze[x][y+1]==0){
      forward();
    }
    else if(leftSensor && maze[x-1][y]==0){
      left();
      forward();
    }
    else if(rightSensor && maze[x+1][y]==0){
      right();
      forward();
    }
    else if(maze[x][y-1]==0){
      back();
    }
    else if(forwardSensor==1){
      forward();
    }
    else if(leftSensor){
      left();
      forward();
    }
    else if(rightSensor){
      right();
      forward();
    }
    else{
      back();
    }
  }
}
