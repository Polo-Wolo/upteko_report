#ifndef INC_PMODNAV_H_
#define INC_PMODNAV_H_

/*********** Function declarations *************/
void NAV_WriteSPI(SPI_HandleTypeDef *hspi, GPIO_TypeDef *csPort, uint16_t csPin, uint8_t addr, uint8_t val);
uint8_t NAV_ReadSPI(SPI_HandleTypeDef *hspi, GPIO_TypeDef *csPort, uint16_t csPin, uint8_t addr);
void NAV_ReadRegister(SPI_HandleTypeDef *hspi, GPIO_TypeDef *csPort, uint16_t csPin, uint8_t addr, uint8_t nBytes, uint8_t *data);

void NAV_InitAG(SPI_HandleTypeDef *hspi, GPIO_TypeDef *csPort, uint16_t csPin);
void NAV_InitMAG(SPI_HandleTypeDef *hspi, GPIO_TypeDef *csPort, uint16_t csPin);
void NAV_InitALT(SPI_HandleTypeDef *hspi, GPIO_TypeDef *csPort, uint16_t csPin);

void NAV_CalibrateIMU(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);

void NAV_Step(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi, UART_HandleTypeDef *uart);

void NAV_GetData(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);
void NAV_GetRawData(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);

void NAV_ReadAccelG(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);
void NAV_ReadAccel(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);
float NAV_ConvertRawToG(PmodNAV *InstancePtr, int16_t rawVal);
void NAV_ReadGyroDps(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);
void NAV_ReadGyro(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);
float NAV_ConvertRawToDps(PmodNAV *InstancePtr, int16_t rawVal);
void NAV_ReadMagGauss(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);
void NAV_ReadMag(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);
float NAV_ConvertRawToGauss(PmodNAV *InstancePtr, int16_t rawVal);

void NAV_ReadPressurehPa(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);
void NAV_ReadPressure(PmodNAV *InstancePtr, SPI_HandleTypeDef *hspi);

void NAV_PrintAccelG(PmodNAV *InstancePtr, UART_HandleTypeDef *uart);
void NAV_PrintAccelRaw(PmodNAV *InstancePtr, UART_HandleTypeDef *uart);
void NAV_PlotUart3Floats(UART_HandleTypeDef *uart, float a, float b, float c);
void NAV_PrintGyroDps(PmodNAV *InstancePtr, UART_HandleTypeDef *uart);
void NAV_PrintMagGauss(PmodNAV *InstancePtr, UART_HandleTypeDef *uart);
void NAV_PrintPressurehPa(PmodNAV *InstancePtr, UART_HandleTypeDef *uart);

void NAV_SendUartAngles(PmodNAV *InstancePtr, UART_HandleTypeDef *uart);
void NAV_SendUartRawFrame(PmodNAV *InstancePtr, UART_HandleTypeDef *uart);

void NAV_MadgwickAHRS(PmodNAV *InstancePtr);

#endif /* INC_PMODNAV_H_ */