//0=left 1=forward 2=right 3=backward
int yon=0;
int x=9;
int y=0;

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
    y-=1;
  }else if(yon==1){
    x+=1;
  }else if(yon==2){
    y+=1;
  }else{
    x-=1;
  }
}








void setup() {

}

void loop() {
  maze[x][y]=1;
  if(yon==0){
    if(rightSensor==1){
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
  }
  else if(yon==1){
    if(forwardSensor==1){
      forward();
    }
    else if(leftSensor){
      left();
      forward();
    }
  }
}
