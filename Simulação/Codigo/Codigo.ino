
 
int MosfetFonte = 4;
int MosfetBateria = 2;
int TensaoFonte = 9;
int TensaoCarga = 8;
int VFonte = 0;

void setup(){
pinMode(MosfetFonte, OUTPUT); // declara o pino do Mosfet fonte como saída
pinMode(MosfetBateria, OUTPUT); // declara o pino do Mosfet fonte saída
pinMode(TensaoFonte, INPUT);     // DECLARA ENTRADA
pinMode(TensaoCarga, INPUT);   // DECLARA ENTRADA
//digitalWrite(MosfetBateria,LOW);
//digitalWrite(MosfetFonte,HIGH);
}
 
void loop(){
VFonte =  analogRead(TensaoFonte);
if(VFonte <= 680)
{
    digitalWrite(MosfetBateria, HIGH);
    digitalWrite(MosfetFonte, LOW);
} 
if(VFonte > 680)
{
    digitalWrite(MosfetBateria, LOW);
    digitalWrite(MosfetFonte, HIGH);
}

}