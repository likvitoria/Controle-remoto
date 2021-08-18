/*
 * authors: Guilherme Zarzicki & Vitoria Lik Santos 
 */

#include <ArduinoQueue.h>
#include <IRremote.h>  

//define dos botoes com os respectivos pinos
#define btn1 A0
#define btn2 A1
#define btn3 A2
#define btn4 A3
#define btn5 A4
#define btn6 A5
#define btn7 2
#define btn8 3
#define btn9 4
#define btn10 5
#define btn11 6
#define btn12 7
#define btn13 8
#define btn14 9
#define btn15 10

int RECV_PIN = 11;  //receptor ir
int SEND_PIN = 12;  //emissor ir

int i;
int modo;   //gravacao ou controle

float valor[15];  //array de codigos ralativos aos botoes  
  
IRrecv irrecv(RECV_PIN);  
IRsend irsend;

decode_results results;
decode_type_t tipo;

ArduinoQueue<unsigned long> intQueue(20);    //criacao da fila

    
void setup(){ 
  
  //define os pinos dos botoes como entrada
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);

  
  pinMode(11, INPUT);    //receptor como entrada
  pinMode(12, OUTPUT);   //emissor como saida
  
  Serial.begin(9600);  
  
  irrecv.enableIRIn(); // Inicializa o receptor IR    
}  
   
void loop(){

  //caso entre no modo de gravacao
  if(digitalRead(btn1 && btn15)==1){
    modo = 1;
  }
  else{
    modo = 0;
  }

  //caso botao simples seja pressionado
  if(digitalRead(btn1)==1){
    intQueue.enqueue(valor[1]);
  }
  
  if(digitalRead(btn2)==1){
    intQueue.enqueue(valor[2]);
  }
  
  if(digitalRead(btn3)==1){
    intQueue.enqueue(valor[3]);
  }
  
  if(digitalRead(btn4)==1){
    intQueue.enqueue(valor[4]);
  }
  
  if(digitalRead(btn5)==1){
    intQueue.enqueue(valor[5]);
  }
  
  if(digitalRead(btn6)==1){
    intQueue.enqueue(valor[6]);
  }
  
  if(digitalRead(btn7)==1){
    intQueue.enqueue(valor[7]);
  }
  
  if(digitalRead(btn8)==1){
    intQueue.enqueue(valor[8]);
  }
  
  if(digitalRead(btn9)==1){
    intQueue.enqueue(valor[9]);
  }
  
  if(digitalRead(btn10)==1){
    intQueue.enqueue(valor[10]);
  }
  
  if(digitalRead(btn11)==1){
    intQueue.enqueue(valor[11]);
  }
  
  if(digitalRead(btn12)==1){
    intQueue.enqueue(valor[12]);
  }
  
  if(digitalRead(btn13)==1){
    intQueue.enqueue(valor[13]);
  }
  
  if(digitalRead(btn14)==1){
    intQueue.enqueue(valor[14]);
  }
  
  if(digitalRead(btn15)==1){
    intQueue.enqueue(valor[15]);
  }

  while(intQueue.itemCount()>0){    //se a fila nao estiver vazia envia os itens nela contidos
    irsend.sendRC5(intQueue.dequeue(), 12);   //12 bits para a codificacao, envia o os itens da fila na ordem que entraram
    delay(100);    //espera 100ms para que o aparelho tenha tempo de decodificar o codigo enviado e fique pronto para o proximo
    Serial.println(intQueue.dequeue(), HEX);  //mostra no serial monitor o valor enviado
  }
    

  if(modo==1){ //caso modo 1, grava novos codigos no controle
    i=0;
    if(irrecv.decode(&results)){ 
      while(i<16){ 
        Serial.print("Valor lido : ");  
        Serial.println(results.value, HEX);    //mostra no serial monitor o valor lido 
        valor[i] = (results.value);
        Serial.print("Atribuido ao botão : "); 
        Serial.println(valor[i]);    //mostra no serial monitor o botao  
        irrecv.resume(); //Le o próximo valor
        i++;
      }
    } 
  }  
}
