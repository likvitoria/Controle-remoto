
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
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

  
  pinMode(11, INPUT);    //receptor como entrada
  pinMode(12, OUTPUT);   //emissor como saida
  
  Serial.begin(9600);  
  
  irrecv.enableIRIn(); // Inicializa o receptor IR    
}  
   
void loop(){

  //caso entre no modo de gravacao
  if(digitalRead(btn1 && btn15) == LOW){
    modo = 1;
  }
  else{
    modo = 0;
  }

  //caso botao simples seja pressionado
  if(digitalRead(btn1)== LOW){
    intQueue.enqueue(valor[1]);
//    Serial.print("teste1\n");
  }
  
  if(digitalRead(btn2) == LOW){
    intQueue.enqueue(valor[2]);
//    Serial.print("teste2\n"); 
  }
  
  if(digitalRead(btn3)== LOW){
    intQueue.enqueue(valor[3]);
//    Serial.print("teste3\n"); 
  }
  
  if(digitalRead(btn4)== LOW){
    intQueue.enqueue(valor[4]);
//    Serial.print("teste4\n");
  }
  
  if(digitalRead(btn5)== LOW){
    intQueue.enqueue(valor[5]);
//    Serial.print("teste5\n");
  }
  
  if(digitalRead(btn6)== LOW){
    intQueue.enqueue(valor[6]);
//    Serial.print("teste6\n"); 
  }
  
  if(digitalRead(btn7)== LOW){
    intQueue.enqueue(valor[7]);
//    Serial.print("teste7\n");
  }
  
  if(digitalRead(btn8)== LOW){
    intQueue.enqueue(valor[8]);
//    Serial.print("teste8\n");
    
  }
  
  if(digitalRead(btn9)== LOW){
    intQueue.enqueue(valor[9]);
//    Serial.print("teste9\n");
  }
  
  if(digitalRead(btn10)== LOW){
    intQueue.enqueue(valor[10]);
//    Serial.print("teste10\n");
     
  }
  
  if(digitalRead(btn11)== LOW){
    intQueue.enqueue(valor[11]);
//    Serial.print("teste11\n");
     
  }
  
  if(digitalRead(btn12)== LOW){
    intQueue.enqueue(valor[12]);
//    Serial.print("teste12\n");
    
  }
  
  if(digitalRead(btn13)== LOW){
    intQueue.enqueue(valor[13]);
//    Serial.print("teste13\n");
   
  }
  
  if(digitalRead(btn14)== LOW){
    intQueue.enqueue(valor[14]);
//    Serial.print("teste14\n");
    
  }
  
  if(digitalRead(btn15)== LOW){
    intQueue.enqueue(valor[15]);
//    Serial.print("teste15\n");
    
  }

  while(intQueue.itemCount()>0){    //se a fila nao estiver vazia envia os itens nela contidos
    irsend.sendRC5(intQueue.dequeue(), 12);   //12 bits para a codificacao, envia o os itens da fila na ordem que entraram
    delay(100);    //espera 100ms para que o aparelho tenha tempo de decodificar o codigo enviado e fique pronto para o proximo
    Serial.println(intQueue.dequeue(), HEX);  //mostra no serial monitor o valor enviado
  }
    

  if(modo == 1){ //caso modo 1, grava novos codigos no controle
    i = 0;
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
