/*
 *  Alexandre RM86499
 *  Victoria Calixto RM82359
 *  Karoline Santato RM83830
 *  Ana Karolina RM83872
 *  Sara Rodrigues RM83967
 */

/*

Professor, durante a construção do sequenciamento do semaforo, 
identificamos que o requisito de "Ao acender a luz amarela para
os carros, a do pedestre deve piscar vermelho", não parecia fluir, 
pois quando o semaforo dos veiculos entra no amarelo anteriormente estava
no verde e o de pedestre no vermelho aguardando o Verde.
Quando o semaforo de veiculos entra no amarelo, o natural é que ele continue no 
vermelho. 
O Vermelho piscante para os pedestres entraria quando estivesse saindo do verde 
avisando que logo fechará e o verde de veiculos acenderá.

Mantivemos o requisito, mas incluimos o loop também.

Obrigado Professor.
*/


//DECLARAÇÃO DE VARIAVEIS

int tf1 = 7000; //VEICULOS VERDE, PEDESTRES VERMELHO
int tf2 = 3000; //VEICULOS AMARELO, PEDESTRES VERMELHO
int tf3 = 4000; //VEICULOS VERMELHO, PEDESTRES VERDE
int tf4 = 3000; //VEICULOS VERMELHO, PEDESTRES VERMELHO PISCANTE (considerar o dl * 5)
int dl = 300; // Delay do VERMELHO PISCANTE PARA OS PEDESTRES

// Portas Semaforo de veículos A
int vei_A_verde = 11;
int vei_A_amare = 10;
int vei_A_verme = 9;

// Portas Semaforo de Pedestres A
int ped_A_verde = 8;
int ped_A_verme = 7;

// Portas Semaforo de veículos B
int vei_B_verde = 6;
int vei_B_amare = 5;
int vei_B_verme = 4;

// Portas Semaforo de Pedestres B
int ped_B_verde = 3;
int ped_B_verme = 2;


void setup()
{
  
  // Inicia a porta serial
  Serial.begin(9600);
  
   
  // Semaforo de veículos A
  pinMode(vei_A_verde, OUTPUT);
  pinMode(vei_A_amare, OUTPUT);
  pinMode(vei_A_verme, OUTPUT);
  
  // Semaforo de Pedestres A
  pinMode(ped_A_verde, OUTPUT);
  pinMode(ped_A_verme, OUTPUT);
  
  // Semaforo de veículos B
  pinMode(vei_B_verde, OUTPUT);
  pinMode(vei_B_amare, OUTPUT);
  pinMode(vei_B_verme, OUTPUT);
  
  // Semaforo de Pedestres B
  pinMode(ped_B_verde, OUTPUT);
  pinMode(ped_B_verme, OUTPUT);
  
  // Desliga os leds do semaforo de Veiculos A
  digitalWrite(vei_A_verde, LOW);
  digitalWrite(vei_A_amare, LOW);
  digitalWrite(vei_A_verme, LOW);

  // Desliga os leds do semaforo de Pedestres A
  digitalWrite(ped_A_verde, LOW);
  digitalWrite(ped_A_verme, LOW);

  // Desliga os leds do semaforo de Veiculos B
  digitalWrite(vei_B_verde, LOW);
  digitalWrite(vei_B_amare, LOW);
  digitalWrite(vei_B_verme, LOW);

  // Desliga os leds do semaforo de Pedestres B
  digitalWrite(ped_B_verde, LOW);
  digitalWrite(ped_B_verme, LOW);
  
}


void loop()
{

  //Fase 1:
  Serial.println("fase 1: VEICULOS VERDE, PEDESTRES VERMELHO");
 
  //Semaforos Veiculos
  digitalWrite(vei_A_verde, HIGH);
  digitalWrite(vei_A_amare, LOW);
  digitalWrite(vei_A_verme, LOW);
  
  digitalWrite(vei_B_verde, HIGH);
  digitalWrite(vei_B_amare, LOW);
  digitalWrite(vei_B_verme, LOW);
  
  // Semaforos de Pedestres
  digitalWrite(ped_A_verde, LOW);
  digitalWrite(ped_B_verde, LOW);
  digitalWrite(ped_A_verme, HIGH);
  digitalWrite(ped_B_verme, HIGH);
	
  delay(tf1);
  
  
  //Fase 2:
  Serial.println("fase 2: VEICULOS AMARELO, PEDESTRES VERMELHO");

  //Semaforos Veiculos
  digitalWrite(vei_A_verde, LOW);
  digitalWrite(vei_A_amare, HIGH);
  digitalWrite(vei_A_verme, LOW);
  
  digitalWrite(vei_B_verde, LOW);
  digitalWrite(vei_B_amare, HIGH);
  digitalWrite(vei_B_verme, LOW);
  
  // Semaforos de Pedestres
  digitalWrite(ped_A_verde, HIGH);
  digitalWrite(ped_B_verde, HIGH);
  
  for (int i=1; i<=10; i++ )
  {
    digitalWrite(ped_A_verme, LOW);
    digitalWrite(ped_B_verme, LOW);
    Serial.println("- FAROL PEDESTRE PISCANTE LIGA");
    delay(dl);
    digitalWrite(ped_A_verme, HIGH);
    digitalWrite(ped_B_verme, HIGH);
    Serial.println("- FAROL PEDESTRE PISCANTE DESLIGA");
    delay(dl);
  }
  
  delay(tf2);
 
  //Fase 3:
  Serial.println("fase 3: VEICULOS VERMELHO, PEDESTRES VERDE");

  //Semaforos Veiculos
  digitalWrite(vei_A_verde, LOW);
  digitalWrite(vei_A_amare, LOW);
  digitalWrite(vei_A_verme, HIGH);
  
  digitalWrite(vei_B_verde, LOW);
  digitalWrite(vei_B_amare, LOW);
  digitalWrite(vei_B_verme, HIGH);
  
  // Semaforos de Pedestres
  digitalWrite(ped_A_verde, HIGH);
  digitalWrite(ped_B_verde, HIGH);
  digitalWrite(ped_A_verme, LOW);
  digitalWrite(ped_B_verme, LOW);
  
  delay(tf3);

  
  //Fase 4:
  Serial.println("fase 4: VEICULOS VERMELHO, PEDESTRES VERMELHO PISCANTE");

  //Semaforos Veiculos
  digitalWrite(vei_A_verde, LOW);
  digitalWrite(vei_A_amare, LOW);
  digitalWrite(vei_A_verme, HIGH);
  
  digitalWrite(vei_B_verde, LOW);
  digitalWrite(vei_B_amare, LOW);
  digitalWrite(vei_B_verme, HIGH);
  
  delay(tf4);
  
  // Esgotando o tempo para o pedestre

  // Semaforos de Pedestres
  digitalWrite(ped_A_verde, LOW);
  digitalWrite(ped_B_verde, LOW);
  
  for (int i=1; i<=5; i++ )
  {
    digitalWrite(ped_A_verme, HIGH);
    digitalWrite(ped_B_verme, HIGH);
    Serial.println("- FAROL PEDESTRE PISCANTE LIGA");
    delay(dl);
    digitalWrite(ped_A_verme, LOW);
    digitalWrite(ped_B_verme, LOW);
    Serial.println("- FAROL PEDESTRE PISCANTE DESLIGA");
    delay(dl);
  }
 
}
