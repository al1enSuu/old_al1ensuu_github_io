
void serialPrint(char outStr[]);

//Useage: myPrintf("[String Content]%[String Content]", int)
//Only support one integer
void serialPrintWithInt(char outStr[], int value);

//Removed from public functions, use serialPrint instead
//int read_usb_serial_none_blocking(char *buf,int length);
//int write_usb_serial_blocking(char *buf,int length);

void serial_init(void);

