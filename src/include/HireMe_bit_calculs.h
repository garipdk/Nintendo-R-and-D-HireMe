#ifndef HireMe_bit_calculs
#define HireMe_bit_calculs

#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))

#define bitsetclear(byte,nbit,bit)   ((bit) == 0 ? (bitclear((byte),(nbit))) : (bitset(byte,nbit)))
#define bitsetclearcheck(byte1,n1bit,byte2,n2bit) (bitsetclear((byte1),(n1bit),bitcheck((byte2),(n2bit))))

#endif // HireMe_bit_calculs