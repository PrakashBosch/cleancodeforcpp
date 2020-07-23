enum vital
{
  ebpm=0,
  eresprate,
  espo2,
  n
};
typedef struct 
    {
	float bpm;
	float resprate;
	float spo2;
	}Params;

bool vital_check(float arg_param, int MIN, int MAX);
bool vital_check(float arg_param, int MIN, int MAX)
{
  return (arg_param < MIN || arg_param > MAX);
}

bool Vital_IsBpmInRange (Params arg_bpm);
bool Vital_IsBpmInRange (Params arg_bpm)
{
  return vital_check(arg_bpm.bpm,70,150);
}

bool Vital_IsResprateInRange (Params arg_respRate);
bool Vital_IsResprateInRange (Params arg_respRate)
{
  return vital_check(arg_respRate.resprate,30,60);
}

bool Vital_IsSpo2InRange (Params arg_spo2);
bool Vital_IsSpo2InRange (Params arg_spo2)
{
  return vital_check(arg_spo2.spo2,80,100);
}

typedef bool (*check)(Params param);
check vital_param[n];

void vital_param_resgister(int ID, check addr);
void vital_param_resgister(int ID, check addr)
{
   vital_param[ID] = addr;
}

void registration(void);
void registration(void)
{
   vital_param_resgister(ebpm,&Vital_IsBpmInRange);
   vital_param_resgister(eresprate,&Vital_IsResprateInRange);
   vital_param_resgister(espo2,&Vital_IsSpo2InRange);
}

bool vitalsAreOk(Params vitals);
bool vitalsAreOk(Params vitals) {
  
  bool ret_status = 0;
  
  for (int i =0; i<n;i++)
    ret_status = ret_status || vital_param[i](vitals);
  
  return !(ret_status);
}

int main()
{
	Params vitcheck;
	vitalsAreOk(vitcheck);
}
