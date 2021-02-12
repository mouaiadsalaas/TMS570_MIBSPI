/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "sys_common.h"
#include "mibspi.h"
/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */

/* USER CODE END */

void main(void)
{

    //here you can use break point to see rxbyf at each step of transfer for tx group
    uint16_t tx_buf[]={0x0000,0x0011,0x0022,0x0033,0x0044,0x0055,0x0066,0x0077,0x0088,0x0099};
    uint16_t tx1_buf[]={0x0000,0x0111,0x0222,0x0333,0x0444,0x0555,0x0666,0x0777,0x0888,0x0999};
    uint16_t tx2_buf[]={0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
    uint16_t rx_buf[10]={0};

    mibspiInit();
    //here we add loop back because we did not send it to real device .when we send to real device we dir the cs pin in halcogen
    //then we remove loop back from here
    mibspiEnableLoopback(mibspiREG1, Analog_Lbk);

    mibspiSetData(mibspiREG1, 0, tx_buf);
    mibspiEnableLoopback(mibspiREG1, Analog_Lbk);
    mibspiTransfer(mibspiREG1, 0);
    while(!(mibspiIsTransferComplete(mibspiREG1, 0)));
    mibspiGetData(mibspiREG1, 0, rx_buf);

    mibspiSetData(mibspiREG1, 1, tx1_buf);
    mibspiEnableLoopback(mibspiREG1, Analog_Lbk);
    mibspiTransfer(mibspiREG1, 1);
    while(!(mibspiIsTransferComplete(mibspiREG1, 1)));
    mibspiGetData(mibspiREG1, 1, rx_buf);

    mibspiSetData(mibspiREG1, 2, tx2_buf);
    mibspiTransfer(mibspiREG1, 2);
    while(!(mibspiIsTransferComplete(mibspiREG1, 2)));
    mibspiGetData(mibspiREG1, 2, rx_buf);




/* USER CODE BEGIN (3) */
    while(1);

/* USER CODE END */

}


/* USER CODE BEGIN (4) */
/* USER CODE END */
