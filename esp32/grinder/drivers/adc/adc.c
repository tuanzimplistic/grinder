#include "log.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "adc.h"

static const char *TAG = "ADC";

esp_adc_cal_characteristics_t adc1_chars;

static void analog_calibration(void)
{
    esp_err_t ret;
    ret = esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_VREF);
    if (ret == ESP_ERR_NOT_SUPPORTED) 
    {
        l(LOG_ERROR, TAG, "Calibration scheme not supported, skip software calibration");
    } 
    else if (ret == ESP_ERR_INVALID_VERSION) 
    {
        l(LOG_WARN, TAG, "eFuse not burnt, skip software calibration");
    } 
    else if (ret == ESP_OK) 
    {
        esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_10, 0, &adc1_chars);
    } 
    else 
    {
        l(LOG_ERROR, TAG, "Invalid arg");
    }
}

void analog_init(void )
{
    analog_calibration();
	adc1_config_width(ADC_WIDTH_BIT_10);
}

uint16_t analog_read(uint8_t pin)
{
    adc1_channel_t channel = ADC1_CHANNEL_6;
    if(pin == 34)
    {
        channel = ADC1_CHANNEL_6;
    }
	return adc1_get_raw(channel);
}