import processing.serial.*;
import processing.net.*;

// Serialクラスのインスタンス
Serial myPort;
Server server;

int val;
int old_val;
int port = 5800;
String str;

int x, y, z;

void setup()
{
  size(400, 400);
  server = new Server(this, port);
  myPort = new Serial(this,"COM5",9600);
  
  //フォント使用開始：サイズ10
  textFont(createFont("Georgia", 50));
}

void draw()
{
  Client client = server.available(); // 接続してきたClient
  
  if(client != null){ // Clientがいるなら
    if((str=client.readString()) != null){ // 文字列を送ってきているなら受信
      println(str); // 受信した文字列を表示
    }
  }
  
  if(str != null){
    myPort.write(str);
    println("Send to Arduino! >"+str);
  }
  str = null;
  
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.read();         // read it and store it in val
  }
  
  background(255);             // Set background to white
  
  if (val != myPort.read()) {
    fill(val*3);                 // set fill to light gray
    server.write(val+"\n");
    println(val);
  }
  rect(100, 100, 200, 200);
  
//  text(x,100,50);
//  text(y,200,50);
  text(val,200,90);
}

