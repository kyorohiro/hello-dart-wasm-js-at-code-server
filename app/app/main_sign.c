#include<stdio.h>
#include "mbedtls/rsa.h"
#include "mbedtls/md.h"
#include "mbedtls/platform.h"

int main(int argc, char const *argv[])
{
    printf("Hello");
    mbedtls_rsa_context rsa;
    mbedtls_mpi N, P, Q, D, E, DP, DQ, QP;
    mbedtls_rsa_init(&rsa,MBEDTLS_RSA_PKCS_V15, 0);
    mbedtls_mpi_init(&N);
    mbedtls_mpi_init(&P);
    mbedtls_mpi_init(&Q);
    mbedtls_mpi_init(&D);
    mbedtls_mpi_init(&E);
    mbedtls_mpi_init(&DP);
    mbedtls_mpi_init(&DQ);
    mbedtls_mpi_init(&QP);


    FILE *file;
    file = fopen("rsa_priv.txt", "rb");
    mbedtls_mpi_read_file(&N, 16, file);
    mbedtls_mpi_read_file(&E, 16, file);
    mbedtls_mpi_read_file(&D, 16, file);
    mbedtls_mpi_read_file(&P, 16, file);
    mbedtls_mpi_read_file(&Q, 16, file);
    mbedtls_mpi_read_file(&DP, 16, file);
    mbedtls_mpi_read_file(&DQ, 16, file);
    mbedtls_mpi_read_file(&QP, 16, file);
    printf("%ld %ld\n",N.n,N.n);
    printf("%ld %ld\n",P.n,P.n);

    int ret = mbedtls_rsa_import(&rsa, &N, &P, &Q, &D, &E);
    printf("ret=%d\n", ret);
    ret = mbedtls_rsa_complete(&rsa);
    printf("ret=%d\n", ret);
    ret = mbedtls_rsa_check_privkey(&rsa);
    printf("ret=%d\n", ret);

    unsigned char hash[32];
    ret = mbedtls_md(
        mbedtls_md_info_from_type( MBEDTLS_MD_SHA256 ),
        "hello",5,hash
    );
    //printf("ret=%d\n", hash);
    unsigned char buf[MBEDTLS_MPI_MAX_SIZE];
    ret = mbedtls_rsa_pkcs1_sign(&rsa, NULL, NULL, MBEDTLS_RSA_PRIVATE,MBEDTLS_MD_SHA256, 20, hash, buf);
    printf("ret=%d\n", ret);
    for(int i=0;i<rsa.len;i++) {
        mbedtls_fprintf(stdout,"%02X%s", buf[i],( i + 1 ) % 16 == 0 ? "\r\n" : " " );
    }
    return 0;
}
