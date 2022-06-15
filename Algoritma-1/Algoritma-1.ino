
#define wbSensor 8 
#define fSensor 14
#define lSensor 15
#define rSensor 16
#define rbSensor 17
#define lbSensor 18

//0=left 1=forward 2=right 3=backward

int yon=0;
int x=9;
int y=0;

//ön 6 sol 5 sağ 4 arka sağ 3 arka sol 2
int maze[ 17 ][ 14 ] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  },  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

int lSensor;
int rSensor;
int fSensor;
int lbSensor;
int rbSensor;

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
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
    
}

void loop() {
  lSensor = digitalRead(lSensor);
  fSensor = digitalRead(fSensor);
  rSensor = digitalRead(rSensor);
  lbSensor = digitalRead(lbSensor);
  rbSensor = digitalRead(rbSensor);
  Serial.print(lSensor);
  Serial.print("\t");
  Serial.print(fSensor);
  Serial.print("\t");
  Serial.print(rSensor);
  Serial.print("\t");
  Serial.print(lbSensor);
  Serial.print("\t");
  Serial.print(rbSensor);
  Serial.println();
  
  
  maze[x][y]=1;
  if(yon == 0){
    if(rSensor == 1 and rbSensor == 1 && maze[x][y+1]==0){
      right();
      forward();
    }
    else if(fSensor == 1 && maze[x-1][y]==0){
      forward();
    }
    else if(lSensor == 1 and lbSensor == 1 && maze[x][y-1] == 0){
      left();
      forward();
    }
    else if(maze[x+1][y] == 0){
      back();
    }
    else if(rSensor == 1 and rbSensor == 1){
      right();
      forward();
    }
    else if(fSensor == 1){
      forward();
    }
    else if(lSensor == 1 and lbSensor == 1){
      left();
      forward();
    }
    else{
      back();
    }
  }
  else if(yon==1){
    if(fSensor == 1 && maze[x][y+1] == 0){
      forward();
    }
    else if(lSensor == 1 and lbSensor == 1 && maze[x-1][y] == 0){
      left();
      forward();
    }
    else if(rSensor == 1 and rbSensor == 1 && maze[x+1][y] == 0){
      right();
      forward();
    }
    else if(maze[x][y-1] == 0){
      back();
    }
    else if(fSensor == 1){
      forward();
    }
    else if(lSensor == 1 and lbSensor == 1){
      left();
      forward();
    }
    else if(rSensor == 1 and rbSensor == 1){
      right();
      forward();
    }
    else{
      back();
    }
  }else if(yon == 2){
    if(lSensor == 1 and lbSensor == 1 && maze[x][y+1]){
     left();
     forward();
    }
    else if(fSensor == 1 && maze[x+1][y]){
     forward();
    }
    else if(rSensor == 1 and rbSensor == 1 && maze[x][y-1]){
      right();
      forward(); 
    }
    else if(maze[x-1][y]==1){
      back();
    }
    else if(lSensor == 1 and lbSensor == 1){
      left();
      forward();
    }
    else if(fSensor == 1){
      forward();
    }
    else if(rSensor == 1 and rbSensor == 1){
      right();
      forward();
    }
    else{
      back();
    }
  }
  else if(yon == 3){
    if(lSensor == 1 and lbSensor == 1 && maze[x+1][y]){
     left();
     forward();
    }
    else if(rSensor == 1 and rbSensor == 1 && maze[x-1][y]){
     forward();
    }
    else if(fSensor == 1 && maze[x][y-1]){
      right();
      forward(); 
    }
    else if(maze[x][y+1]==1){
      back();
    }
    else if(lSensor==1){
      left();
      forward();
    }
    else if(rSensor == 1 and rbSensor == 1){
      right();
      forward();
    }
    else if(fSensor == 1){
      forward();
    }
    else{
      back();
    }
  }
}
