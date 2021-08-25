/*
 * authors: Guilherme Zarzicki & Vitoria Lik Santos 
 */

#include <Arduino_FreeRTOS.h>
#include <ArduinoQueue.h>
#include <IRremote.h>  

//define das tasks
void TaskModo( void *pvParameters );

void TaskBtn0( void *pvParameters );
void TaskBtn1( void *pvParameters );
void TaskBtn2( void *pvParameters );
void TaskBtn3( void *pvParameters );
void TaskBtn4( void *pvParameters );
void TaskBtn5( void *pvParameters );
void TaskBtn6( void *pvParameters );
void TaskBtn7( void *pvParameters );
void TaskBtn8( void *pvParameters );
void TaskBtn9( void *pvParameters );
void TaskBtn10( void *pvParameters );
void TaskBtn11( void *pvParameters );
void TaskBtn12( void *pvParameters );
void TaskBtn13( void *pvParameters );
void TaskBtn14( void *pvParameters );

void TaskEmissor( void *pvParameters );


int RECV_PIN = 12;  //receptor ir
int SEND_PIN = 11;  //emissor ir

int i;
int modo;   //gravacao ou controle

float valor[15];  //array de codigos ralativos aos botoes  
float sinal;

IRrecv irrecv(RECV_PIN);  
IRsend irsend;

decode_results results;
decode_type_t tipo;

ArduinoQueue<float> intQueue(20);    //criacao da fila

    
void setup(){ 
  xTaskCreate(TaskModo, "Modo", 128, NULL, 1, NULL);
  
  xTaskCreate(TaskBtn0, "Botão_0", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn1, "Botão_1", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn2, "Botão_2", 128, NULL, 2, NULL); 
  xTaskCreate(TaskBtn3, "Botão_3", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn4, "Botão_4", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn5, "Botão_5", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn6, "Botão_6", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn7, "Botão_7", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn8, "Botão_8", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn9, "Botão_9", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn10, "Botão_10", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn11, "Botão_11", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn12, "Botão_12", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn13, "Botão_13", 128, NULL, 2, NULL);
  xTaskCreate(TaskBtn14, "Botão_14", 128, NULL, 2, NULL);
  
  xTaskCreate(TaskEmissor, "Emissão", 128, NULL, 1, NULL);
            
}  
   
void loop(){
 
}

// tasks

void TaskModo(void *pvParameters){
  
  pinMode(A0, INPUT_PULLUP);  //botão 0
  pinMode(10, INPUT_PULLUP);  // botão 15

  i=0;
  
  while(1){
    if(digitalRead(A0 && 10) == LOW){
      while(i < 15){ 
        if(irrecv.decode(&results)){
          Serial.print("Valor lido : ");  
          Serial.println(results.value, HEX);    //mostra no serial monitor o valor lido 
          valor[i] = (results.value);
          Serial.print("Atribuido ao botão : "); 
          Serial.println(i);    //mostra no serial monitor o botao
          delay(500);  
          irrecv.resume(); //Le o próximo valor
          i++;
        }
      } 
    }
    vTaskDelay(1);
  }
}



void TaskBtn0(void *pvParameters){
  
  pinMode(A0, INPUT_PULLUP);
  
  while(1){
    if(digitalRead(A0)== LOW){
      intQueue.enqueue(valor[0]);
      Serial.println("O botão 0 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn1(void *pvParameters){

  pinMode(A1, INPUT_PULLUP);

  while(1){
    if(digitalRead(A1)== LOW){
      intQueue.enqueue(valor[1]);
      Serial.println("O botão 1 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn2(void *pvParameters){

  pinMode(A2, INPUT_PULLUP);

  while(1){
    if(digitalRead(A2)== LOW){
      intQueue.enqueue(valor[2]);
      Serial.println("O botão 2 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn3(void *pvParameters){

  pinMode(A3, INPUT_PULLUP);

  while(1){
    if(digitalRead(A3)== LOW){
      intQueue.enqueue(valor[3]);
      Serial.println("O botão 3 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn4(void *pvParameters){

  pinMode(A4, INPUT_PULLUP);

  while(1){
    if(digitalRead(A4)== LOW){
      intQueue.enqueue(valor[4]);
      Serial.println("O botão 4 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn5(void *pvParameters){

  pinMode(A5, INPUT_PULLUP);

  while(1){
    if(digitalRead(A5)== LOW){
      intQueue.enqueue(valor[5]);
      Serial.println("O botão 5 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn6(void *pvParameters){

  pinMode(2, INPUT_PULLUP);

  while(1){
    if(digitalRead(2)== LOW){
      intQueue.enqueue(valor[6]);
      Serial.println("O botão 6 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn7(void *pvParameters){

  pinMode(3, INPUT_PULLUP);

  while(1){
    if(digitalRead(3)== LOW){
      intQueue.enqueue(valor[7]);
      Serial.println("O botão 7 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn8(void *pvParameters){

  pinMode(4, INPUT_PULLUP);

  while(1){
    if(digitalRead(4)== LOW){
      intQueue.enqueue(valor[8]);
      Serial.println("O botão 8 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn9(void *pvParameters){

  pinMode(5, INPUT_PULLUP);

  while(1){
    if(digitalRead(5)== LOW){
      intQueue.enqueue(valor[9]);
      Serial.println("O botão 9 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn10(void *pvParameters){

  pinMode(6, INPUT_PULLUP);

  while(1){
        if(digitalRead(6)== LOW){
      intQueue.enqueue(valor[10]);
      Serial.println("O botão 10 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn11(void *pvParameters){

  pinMode(7, INPUT_PULLUP);

  while(1){
    if(digitalRead(7)== LOW){
      intQueue.enqueue(valor[11]);
      Serial.println("O botão 11 foi pressionado");
    } 
  }
  vTaskDelay(1);
}

void TaskBtn12(void *pvParameters){

  pinMode(8, INPUT_PULLUP);

  while(1){
    if(digitalRead(8)== LOW){
      intQueue.enqueue(valor[12]);
      Serial.println("O botão 12 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn13(void *pvParameters){

  pinMode(9, INPUT_PULLUP);

  while(1){
    if(digitalRead(9)== LOW){
      intQueue.enqueue(valor[13]);
      Serial.println("O botão 13 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskBtn14(void *pvParameters){

  pinMode(10, INPUT_PULLUP);

  while(1){
    if(digitalRead(10)== LOW){
      intQueue.enqueue(valor[14]);
      Serial.println("O botão 14 foi pressionado");
    }
  }
  vTaskDelay(1);
}

void TaskEmissor(void *pvParameters){
 
  while(1){
    if(intQueue.itemCount() > 0){
      sinal = intQueue.dequeue();
      Serial.println(sinal, HEX);  //mostra no serial monitor o valor enviado
      irsend.sendRC5(sinal, 12);   //12 bits para a codificacao, envia o os itens da fila na ordem que entraram
    }
  }
  vTaskDelay(10); //para que o sinal tenha tempo de ser enviado e lido
}
