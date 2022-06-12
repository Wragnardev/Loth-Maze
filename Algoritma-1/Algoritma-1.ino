#define wbSensor 8 //siyah beyaz sensör
#define fSensor 6 //ön sensör
#define lSensor 5 //sol sensör
#define rSensor 4 //sağ sensör
#define rbSensor 3 //sağ arka sensör
#define lbSensor 2 //sol arka sensör

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
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
}

void loop() {
  lSensor = digitalRead(lSensor);
  fSensor = digitalRead(fSensor);
  rSensor = digitalRead(rSensor);
  lbSensor = digitalRead(lbSensor);
  rbSensor = digitalRead(rbSensor);
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
    else if(rSensor == 1 rbSensor == 1 && maze[x-1][y]){
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
