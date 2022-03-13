int firstLight = 1; //开始灯的位置
int lastLight = 5;  //结束灯的位置
int Time = 500; //持续时间
int buttonPin = 8;  //链接按键的引脚
int buttonState = 0;  //存储按键状态的变量

void setup() {
  // put your setup code here, to run once:
  for(int pinLocation = firstLight; pinLocation <= lastLight; pinLocation++){
    pinMode(pinLocation, OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void pattern1(){
    //从头到尾
    for(int location = firstLight; location <= lastLight; location++){
      digitalWrite(location,  HIGH);
      delay(Time);
      digitalWrite(location, LOW);
    }
}

void pattern2(){
  //从尾到头
    for(int location = lastLight; location >= firstLight; location--){
      digitalWrite(location,  HIGH);
      delay(Time);
      digitalWrite(location, LOW);
    }
}

void pattern3(){
  //全亮后从一边开始灭
    for(int location = lastLight; location >= firstLight; location--){
      digitalWrite(location,  HIGH);
    }
    delay(Time * 5);
    for(int location = lastLight; location >= firstLight; location--){
      digitalWrite(location, LOW);
    }
}

void pattern4(){
  //从两边往中间先亮后灭
    int first = firstLight, last = lastLight;
    while(first <= last){
      digitalWrite(first, HIGH);
      delay(Time);
      digitalWrite(first++, LOW);
      if(first > last)  break;
      digitalWrite(last, HIGH);
      delay(Time);
      digitalWrite(last--, LOW);
      if(first > last)  break;
    }
}

void pattern5(){
  //从两边往中间亮
    int first = firstLight, last = lastLight;
    while(first <= last){
      digitalWrite(first++, HIGH);
      delay(Time);
      if(first > last)  break;
      digitalWrite(last--, HIGH);
      delay(Time);
      if(first > last)  break;
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  int flag = 0;
  int location = rand() % 5 + 1;
  if(buttonState == HIGH){
    flag = 0;
    pattern1();
    pattern2();
    pattern3();
    pattern4();
    pattern5();
  }else{
//    int location;
//    if(!flag){
//      location = rand() % 5 + 1;
//    }
//    flag = 1;
    if(location == 1){
      pattern1();
    }
    if(location == 2){
      pattern2();
    }
    if(location == 3) {
      pattern3();
    }
    if(location == 4) {
      pattern4();
    }
    if(location == 5) {
      pattern5();
    }
  }

  
}