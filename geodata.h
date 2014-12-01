#ifndef __GEODATA_H__
#define __GEODATA_H__
#include <stdint.h>

#define GEODATA_MAGIC 0x9E00

typedef struct {
	uint32_t magic;
	uint32_t const_count; //��������
	uint32_t const_table_offset;
	uint32_t geo_item_count;
	uint32_t geo_item_offset;
	char rest[12]; //�����ֶΡ�
}geo_head_t;

/**
 * ��������
 */
typedef struct {
	int begin;  	//begin ������ڳ�������ƫ�ơ�
	int len;		//���������ȣ�����һ��\0
}const_index_t;

typedef struct {
	uint32_t ip_begin;
	uint32_t ip_end;
	uint32_t province; 
	uint32_t city;
	uint32_t isp;
}geo_item_t;

typedef struct {
	uint32_t ip_begin;
	uint32_t ip_end;
	const char* province;
	int province_len;
	const char* city;
	int city_len;
	const char* isp;
	int isp_len;
}geo_result_t;

typedef struct {
	char* ptr;
	int size;
}geo_ctx_t;

#define cvalue(indexs,buf, index) (&buf[indexs[index].begin])
#define clength(indexs, index) (indexs[index].len)
geo_ctx_t* geo_new();
int geo_init(geo_ctx_t* geo_ctx, const char* geodatafile);
void geo_destroy(geo_ctx_t* geo_ctx);
int geo_find2(geo_ctx_t* geo_ctx, uint32_t ip, geo_result_t* result);
int geo_find(geo_ctx_t* geo_ctx, const char* ip, geo_result_t* result);

/// utils 
const char* long2ip(uint32_t ip_long);
uint32_t ip2long(const char *ip,int len);

#endif
