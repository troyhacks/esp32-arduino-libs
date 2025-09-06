/*
* SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
*
* SPDX-License-Identifier: Apache-2.0
*/

/* prevent recursive inclusion */
#ifndef __ESP_HOSTED_API_PRIV_H__
#define __ESP_HOSTED_API_PRIV_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stdbool.h"
#include "esp_wifi.h"
#include "esp_wifi_remote.h"
#include "esp_hosted_api_types.h"
#include "esp_hosted_ota.h"
#include "port_esp_hosted_host_wifi_config.h"

/* Remote WiFi API Functions - Port/Implementation Specific */
esp_err_t esp_wifi_remote_init(const wifi_init_config_t *arg);
esp_err_t esp_wifi_remote_deinit(void);
esp_err_t esp_wifi_remote_set_mode(wifi_mode_t mode);
esp_err_t esp_wifi_remote_get_mode(wifi_mode_t* mode);
esp_err_t esp_wifi_remote_start(void);
esp_err_t esp_wifi_remote_stop(void);
esp_err_t esp_wifi_remote_connect(void);
esp_err_t esp_wifi_remote_disconnect(void);
esp_err_t esp_wifi_remote_set_config(wifi_interface_t interface, wifi_config_t *conf);
esp_err_t esp_wifi_remote_get_config(wifi_interface_t interface, wifi_config_t *conf);
esp_err_t esp_wifi_remote_get_mac(wifi_interface_t mode, uint8_t mac[6]);
esp_err_t esp_wifi_remote_set_mac(wifi_interface_t mode, const uint8_t mac[6]);

esp_err_t esp_wifi_remote_scan_start(const wifi_scan_config_t *config, bool block);
esp_err_t esp_wifi_remote_scan_stop(void);
esp_err_t esp_wifi_remote_scan_get_ap_num(uint16_t *number);
esp_err_t esp_wifi_remote_scan_get_ap_record(wifi_ap_record_t *ap_record);
esp_err_t esp_wifi_remote_scan_get_ap_records(uint16_t *number, wifi_ap_record_t *ap_records);
esp_err_t esp_wifi_remote_clear_ap_list(void);
esp_err_t esp_wifi_remote_restore(void);
esp_err_t esp_wifi_remote_clear_fast_connect(void);
esp_err_t esp_wifi_remote_deauth_sta(uint16_t aid);
esp_err_t esp_wifi_remote_sta_get_ap_info(wifi_ap_record_t *ap_info);
esp_err_t esp_wifi_remote_set_ps(wifi_ps_type_t type);
esp_err_t esp_wifi_remote_get_ps(wifi_ps_type_t *type);
esp_err_t esp_wifi_remote_set_storage(wifi_storage_t storage);
esp_err_t esp_wifi_remote_set_bandwidth(wifi_interface_t ifx, wifi_bandwidth_t bw);
esp_err_t esp_wifi_remote_get_bandwidth(wifi_interface_t ifx, wifi_bandwidth_t *bw);
esp_err_t esp_wifi_remote_set_channel(uint8_t primary, wifi_second_chan_t second);
esp_err_t esp_wifi_remote_get_channel(uint8_t *primary, wifi_second_chan_t *second);
esp_err_t esp_wifi_remote_set_country_code(const char *country, bool ieee80211d_enabled);
esp_err_t esp_wifi_remote_get_country_code(char *country);
esp_err_t esp_wifi_remote_set_country(const wifi_country_t *country);
esp_err_t esp_wifi_remote_get_country(wifi_country_t *country);
esp_err_t esp_wifi_remote_ap_get_sta_list(wifi_sta_list_t *sta);
esp_err_t esp_wifi_remote_ap_get_sta_aid(const uint8_t mac[6], uint16_t *aid);
esp_err_t esp_wifi_remote_sta_get_rssi(int *rssi);
esp_err_t esp_wifi_remote_set_protocol(wifi_interface_t ifx, uint8_t protocol_bitmap);
esp_err_t esp_wifi_remote_get_protocol(wifi_interface_t ifx, uint8_t *protocol_bitmap);
esp_err_t esp_wifi_remote_set_max_tx_power(int8_t power);
esp_err_t esp_wifi_remote_get_max_tx_power(int8_t *power);
esp_err_t esp_wifi_remote_sta_get_negotiated_phymode(wifi_phy_mode_t *phymode);
esp_err_t esp_wifi_remote_sta_get_aid(uint16_t *aid);
esp_err_t esp_wifi_remote_set_inactive_time(wifi_interface_t ifx, uint16_t sec);
esp_err_t esp_wifi_remote_get_inactive_time(wifi_interface_t ifx, uint16_t *sec);

#if H_WIFI_HE_SUPPORT
esp_err_t esp_wifi_remote_sta_twt_config(wifi_twt_config_t *config);
esp_err_t esp_wifi_remote_sta_itwt_setup(wifi_itwt_setup_config_t *setup_config);
esp_err_t esp_wifi_remote_sta_itwt_teardown(int flow_id);
esp_err_t esp_wifi_remote_sta_itwt_suspend(int flow_id, int suspend_time_ms);
esp_err_t esp_wifi_remote_sta_itwt_get_flow_id_status(int *flow_id_bitmap);
esp_err_t esp_wifi_remote_sta_itwt_send_probe_req(int timeout_ms);
esp_err_t esp_wifi_remote_sta_itwt_set_target_wake_time_offset(int timeout_us);
#endif

#if H_WIFI_DUALBAND_SUPPORT
/* Dual-band WiFi API (Depends upon co-processor used) */
esp_err_t esp_wifi_remote_set_band(wifi_band_t band);
esp_err_t esp_wifi_remote_get_band(wifi_band_t *band);
esp_err_t esp_wifi_remote_set_band_mode(wifi_band_mode_t band_mode);
esp_err_t esp_wifi_remote_get_band_mode(wifi_band_mode_t *band_mode);
esp_err_t esp_wifi_remote_set_protocols(wifi_interface_t ifx, wifi_protocols_t *protocols);
esp_err_t esp_wifi_remote_get_protocols(wifi_interface_t ifx, wifi_protocols_t *protocols);
esp_err_t esp_wifi_remote_set_bandwidths(wifi_interface_t ifx, wifi_bandwidths_t *bw);
esp_err_t esp_wifi_remote_get_bandwidths(wifi_interface_t ifx, wifi_bandwidths_t *bw);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __ESP_HOSTED_API_PRIV_H__ */
