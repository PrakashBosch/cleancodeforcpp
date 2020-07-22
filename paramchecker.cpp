typedef enum
{
  bpm=0,
  resprate,
  spo2,
  n
}

bool vital_check(float arg_param, int MIN, int MAX);
bool vital_check(float arg_param, int MIN, int MAX)
{
  return (arg_param < MIN || arg_param > MAX);
}

bool vital_checkbpm (float arg_bpm);
bool vital_checkbpm (float arg_bpm)
{
  return vital_check(arg_bpm,70,150);
}

bool vital_checkrespRate (float arg_respRate);
bool vital_checkrespRate (float arg_respRate)
{
  return vital_check(arg_respRate,30,60);
}

bool vital_checkspo2 (float arg_spo2);
bool vital_checkspo2 (float arg_spo2)
{
  return vital_check(arg_spo2,80,100);
}

bool (*vital_param[n])(float param);

void vital_param_resgister(int ID,vital_param *addr);
void vital_param_resgister(ID, vital_param *addr)
{
   vital_param[ID] = &addr;
}

void registration(void)
{
   vital_param_resgister(bpm,&vital_checkbpm);
 vital_param_resgister(resprate,&vital_checkrespRate);
 vital_param_resgister(spo2,&vital_checkspo2);
}

bool vitalsAreOk(float *vitals) {
  
  bool ret_status = FALSE;
  
  for (int i =0; i<n;i++)
    ret_status = ret_status || vital_param[i](vitals[i]);
  
  return !(ret_status);
}
