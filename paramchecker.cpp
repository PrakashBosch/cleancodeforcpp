
bool vital_check(float arg_param, int MIN, int MAX)
{
  return (arg_param < MIN || arg_param > MAX);
}

bool vital_checkbpm (float arg_bpm)
{
  return vital_check(arg_bpm,70,150);
}

bool vital_checkrespRate (float arg_respRate)
{
  return vital_check(arg_respRate,30,60);
}

bool vital_checkrespRate (float arg_spo2)
{
  return vital_check(arg_spo2,80,100);
}
  

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  
  return !(vital_checkbpm(bpm) || vital_checkspo2(spo2) || vital_checkrespRate(respRate));
}
