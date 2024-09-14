#include "protocol.h"

PDU *mkPDU(unit uiMsgLen)
{
    unit uiPDULen = sizeof(PDU) + uiMsgLen;
    PDU *pdu = (PDU*)malloc(uiPDULen);
    if(NULL == pdu){
        exit(EXIT_FAILURE);
    }
    memset(pdu, 0, uiPDULen);//将分配的内存区域置零（清空），避免垃圾数据
    pdu->uiMsgLen = uiMsgLen;
    pdu->uiPDULen = uiPDULen;
    return pdu;
}
