#define WAIT_TIME (20)//[ms]

int num=0;  //実際に割る数
int g_count=0;  //loopの中で高速で増えていく

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {

  if(g_count > 50){  //g_countが50になったら以下を実行
    g_count=0;  //次に備えて初期化
    
    if(num<100){  //100まで
      num++;

      char txt[128];  //表示内容格納用
      sprintf(txt,"%d",num);
      Serial.print(txt);  //数字表示
      
      if(num%3==0 && num%5==0){  //15で割り切れるとき
        Serial.print(":FizzBuzz");
      }
      else if(num%3==0){  //3で割り切れるとき
        Serial.print(":Buzz");
      }
      else if(num%5==0){  //5で割り切れるとき
        Serial.print(":Fizz");
      }
      sprintf(txt,"\n");
      Serial.print(txt);  //改行表示
    }
  }

  g_count ++;  //ここで高速でカウントアップされる
  delay(WAIT_TIME);  //20ms待つ

}
