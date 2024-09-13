
/*  Titulo : programa de Diseno conceptual 
 *  Fecha de modificacion de Codigo:  09/07/2024
 *  Fecha de ultima actualizacion: 09/07/2024
 *  Revision Actual: A
 *    Rev A : Initial Release -- DMC 
 *   
*/

#define adelante d  /* Definiciones de constantes que recibira el robot desde la aplicacion*/
#define atras a 
#define izquierda i
#define derecha d 
#define lat_izq k 
#define lat_der l 
#define paro s

//Declaracion de los pines en los motores
#define MOT_A1_PIN 10
#define MOT_A2_PIN 9
#define MOT_B1_PIN 6
#define MOT_B2_PIN 5


void setup() {
  Serial.begin(9600); //Velocidad de comunicación Serial

  //Configura los pines de salida
  // Set all the motor control inputs to OUTPUT
  pinMode(MOT_A1_PIN, OUTPUT);
  pinMode(MOT_A2_PIN, OUTPUT);
  pinMode(MOT_B1_PIN, OUTPUT);
  pinMode(MOT_B2_PIN, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(MOT_A1_PIN, LOW);
  digitalWrite(MOT_A2_PIN, LOW);
  digitalWrite(MOT_B1_PIN, LOW);
  digitalWrite(MOT_B2_PIN, LOW);
}
//Main 
void loop() {
  char crt; //Variable caracter que recibe los datos via Bluetooth

  //Preguntar si hay dato disponible en el puerto serial
  if(Serial.available()){
    crt = Serial.read();

    // Instruccion para ir hacia adelante
    if(crt == 'd'){ 
      set_motor_currents (255,255); 
    }

    // Instruccion para ir hacia atras
    if(crt == 'a'){
      set_motor_currents (-255,-255);
    }

    // Instruccion para ir hacia izquierda
    if(crt == 'i'){ 
      set_motor_currents(-255,255);
    }

  // Instruccion para ir hacia derecha
    if(crt == 'd'){ 
      set_motor_currents(255,-255);
    }
    
  // Instruccion para ir lateral izq
    if(crt == 's'){ 
      set_motor_currents(0,0);
    }
  }
}


//Funciones declaradas 
/// Set the current on a motor channel using PWM and directional logic.
///
/// \param pwm    PWM duty cycle ranging from -255 full reverse to 255 full forward
/// \param IN1_PIN  pin number xIN1 for the given channel
/// \param IN2_PIN  pin number xIN2 for the given channel
void set_motor_pwm(int pwm, int IN1_PIN, int IN2_PIN)
{
  if (pwm < 0) {  // reverse speeds
    analogWrite(IN1_PIN, -pwm);
    digitalWrite(IN2_PIN, LOW);

  } else { // stop or forward
    digitalWrite(IN1_PIN, LOW);
    analogWrite(IN2_PIN, pwm);
  }
}

/// Set the current on both motors.
///
/// \param pwm_A  motor A PWM, -255 to 255
/// \param pwm_B  motor B PWM, -255 to 255
void set_motor_currents(int pwm_A, int pwm_B)
{
  set_motor_pwm(pwm_A, MOT_A1_PIN, MOT_A2_PIN);
  set_motor_pwm(pwm_B, MOT_B1_PIN, MOT_B2_PIN);
}
