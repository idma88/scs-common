#ifndef _SCS_AES
#define _SCS_AES

#include "../libs/tiny-AES-c/aes.hpp"

namespace SCS
{
    typedef ::AES_ctx AES_ctx;

    void AES_init_ctx(AES_ctx* ctx, const uint8_t* key)
    {
        ::AES_init_ctx(ctx, key);
    }

#if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))
    void AES_init_ctx_iv(AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)
    {
        ::AES_init_ctx_iv(ctx, key, iv);
    }

    void AES_ctx_set_iv(AES_ctx* ctx, const uint8_t* iv)
    {
        ::AES_ctx_set_iv(ctx, iv);
    }
#endif

#if defined(ECB) && (ECB == 1)
    void AES_ECB_encrypt(const AES_ctx* ctx, uint8_t* buf)
    {
        ::AES_ECB_encrypt(ctx, buf);
    }

    void AES_ECB_decrypt(const AES_ctx* ctx, uint8_t* buf)
    {
        ::AES_ECB_decrypt(ctx, buf);
    }
#endif // #if defined(ECB) && (ECB == !)

#if defined(CBC) && (CBC == 1)
    void AES_CBC_encrypt_buffer(AES_ctx* ctx, uint8_t* buf, uint32_t length)
    {
        ::AES_CBC_encrypt_buffer(ctx, buf, length);
    }

    void AES_CBC_decrypt_buffer(AES_ctx* ctx, uint8_t* buf, uint32_t length)
    {
        ::AES_CBC_decrypt_buffer(ctx, buf, length);
    }
#endif // #if defined(CBC) && (CBC == 1)

#if defined(CTR) && (CTR == 1)
    void AES_CTR_xcrypt_buffer(AES_ctx* ctx, uint8_t* buf, uint32_t length)
    {
        ::AES_CTR_xcrypt_buffer(ctx, buf, length);
    }
#endif // #if defined(CTR) && (CTR == 1)
} // namespace SCS

#endif //_SCS_AES
