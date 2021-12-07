#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
/*ADMUX BINS*/
#define REFS0 6 /*to select reference voltage*/
#define REFS1 7 /*to select reference voltage*/
#define ADLAR 5 /*to select right reading (0) or left reading (1)*/
/*ADCSRA BINS*/
#define ADEN  7 /*Enable ADC*/
#define ADSC  6 /*Start Conversion*/
#define ADATE 5 /*Auto Trigger*/
#define ADIE  3 /*Interrupt Enable*/
#define ADPS2 2 /*Select between Prescalers*/
#define ADPS1 1 /*Select between Prescalers*/
#define ADPS0 0 /*Select between Prescalers*/
/*SFIOR ADC BINS*/
#define ADTS2 7 /*Select ADC Auto Trigger Source*/
#define ADTS1 6 /*Select ADC Auto Trigger Source*/
#define ADTS0 5 /*Select ADC Auto Trigger Source*/
#endif /* ADC_PRIVATE_H_ */
