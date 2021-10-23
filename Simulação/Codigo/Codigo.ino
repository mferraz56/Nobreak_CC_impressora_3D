unsigned long tempo_anterior = 0; // variavel
const long intervalo = 5000;      //Intervalo 5 seg

int LedAzul = 4;
int LedVerde = 5;
int LedAmarelo = 6;
int LedVermelho = 7;
int VFonte; // variavel tensão fonte
int VBateria;

void setup()
{
    pinMode(2, OUTPUT); // mosfet bateria
    pinMode(3, OUTPUT); // mosfet fonte
    pinMode(A0, INPUT); // leitura bateria
    pinMode(A1, INPUT); // leitura fonte

    pinMode(4, OUTPUT); // saida led azul
    pinMode(5, OUTPUT); // saida led verde
    pinMode(6, OUTPUT); // saida led amarelo
    pinMode(7, OUTPUT); // saida led vermelho

    //digitalWrite(2,LOW);
    //digitalWrite(3,HIGH);
}

void loop()
{
    VFonte = analogRead(A1);

    if (VFonte <= 700)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
    }
    if (VFonte > 700)
    {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
    }

    unsigned long timer = millis(); // inicia em 0 até o infinito
    if ((timer - tempo_anterior) == intervalo)
    {
        tempo_anterior = timer; //armazenando o tempo anterior
        VBateria = analogRead(A0);
        if (VBateria <= 777)
        {
            digitalWrite(LedVermelho, HIGH);
            digitalWrite(LedAmarelo, LOW);
            digitalWrite(LedVerde, LOW);
            digitalWrite(LedAzul, LOW);
        }
        if (VBateria > 777 && VBateria <= 847)
        {
            digitalWrite(LedVermelho, LOW);
            digitalWrite(LedAmarelo, HIGH);
            digitalWrite(LedVerde, LOW);
            digitalWrite(LedAzul, LOW);
        }
        if (VBateria > 847 && VBateria <= 918)
        {
            digitalWrite(LedVermelho, LOW);
            digitalWrite(LedAmarelo, LOW);
            digitalWrite(LedVerde, HIGH);
            digitalWrite(LedAzul, LOW);
        }
        if (VBateria > 918 && VBateria <= 1023)
        {
            digitalWrite(LedVermelho, LOW);
            digitalWrite(LedAmarelo, LOW);
            digitalWrite(LedVerde, LOW);
            digitalWrite(LedAzul, HIGH);
        }
    }
}