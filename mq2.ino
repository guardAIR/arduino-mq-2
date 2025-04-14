const int PINO_SENSOR_MQ2 =A0; //Saída do sensor na A0

const int VALOR_MINIMO=100;//Valor mínimo de captação
const int VALOR_MAXIMO=1000;//Valor máximo da captação

void setup() {//Função que será executada
  Serial.begin(9600); //Inicia a comunicação a 9600 bauds
  while (!Serial);
  Serial.println("%");
}

void loop() {//Função que será executada continuamente
  int valorSensor= analogRead(PINO_SENSOR_MQ2);//A porta analógica do sensor
  float porcentagem=((float)(valorSensor - VALOR_MINIMO) / (VALOR_MAXIMO - VALOR_MINIMO))*100;//Transforma em porcentagem
    if(porcentagem < 0){//Se o sensor estiver negativo
      porcentagem = 0;//Não está funcionando
    }else if (porcentagem > 100){//Se for 1
      porcentagem = 100;//Está ligado
    }
Serial.println(porcentagem);

delay(500);// Tempo entre os resultados
}