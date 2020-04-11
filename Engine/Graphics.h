#pragma once

#include "BWin.h"
#include <d3d11.h>
#include <wrl.h>
#include "BException.h"
#include "Colors.h"
#include "Surface.h"
#include "Rect.h"

class Graphics
{
public:
	class Exception : public BException
	{
	public:
		Exception(HRESULT hr, const std::wstring& note, const wchar_t* file, unsigned int line);
		std::wstring GetErrorName() const;
		std::wstring GetErrorDescription() const;
		virtual std::wstring GetFullMessage() const override;
		virtual std::wstring GetExceptionType() const override;
	private:
		HRESULT hr;
	};
private:
	// vertex format for the framebuffer fullscreen textured quad
	struct FSQVertex
	{
		float x, y, z;		// position
		float u, v;			// texcoords
	};
public:
	Graphics(class HWNDKey& key);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	void EndFrame();
	void BeginFrame();
	void putPixel(int x, int y, int r, int g, int b)
	{
		putPixel(x, y, { unsigned char(r),unsigned char(g),unsigned char(b) });
	}
	void putPixel(int x, int y, Color c)
	{
		putPixel(Graphics::ScreenWidth * y + x, c);
	}
	void putPixel(int i, Color c);


	void drawRect(RectI rect, RectI clip, Color c);
	void drawRect(int x0, int y0, int x1, int y1, Color c)
	{
		drawRect({ x0,x1,y0,y1 }, c);
	}
	void drawRect(RectI rect, Color c)
	{
		drawRect(rect, getScreenRect(), c);
	}
	void drawRectDim(int x0, int y0, int width, int height, Color c)
	{
		drawRect(x0, y0, x0 + width, y0 + height, c);
	}
	void drawSpriteNonChroma(int x, int y, const Surface& s)
	{
		drawSpriteNonChroma(x, y, s.getRect(), s);
	}
	void drawSpriteNonChroma(int x, int y, const RectI& srcRect, const Surface& s)
	{
		drawSpriteNonChroma(x, y, srcRect, getScreenRect(), s);
	}
	void drawSpriteNonChroma(int x, int y, RectI srcRect, const RectI& clip, const Surface& s);
	void drawSpriteNonChroma(const VecI2& pos, const Surface& s)
	{
		drawSpriteNonChroma(pos.x, pos.y, s);
	}
	void drawSpriteNonChroma(const VecI2& pos, const RectI& srcRect, const Surface& s)
	{
		drawSpriteNonChroma(pos.x, pos.y, srcRect, s);
	}
	void drawSpriteNonChroma(const VecI2& pos, RectI srcRect, const RectI& clip, const Surface& s)
	{
		drawSpriteNonChroma(pos.x, pos.y, srcRect, clip, s);
	}


	void drawSprite(int x, int y, const Surface& s, Color chroma = Colors::Magenta)
	{
		drawSprite(x, y, s.getRect(), s, chroma);
	}
	void drawSprite(int x, int y, const RectI& srcRect, const Surface& s, Color chroma = Colors::Magenta)
	{
		drawSprite(x, y, srcRect, getScreenRect(), s, chroma);
	}
	void drawSprite(int x, int y, RectI srcRect, const RectI& clip, const Surface& s, Color chroma = Colors::Magenta);
	void drawSprite(const VecI2& pos, const Surface& s, Color chroma = Colors::Magenta)
	{
		drawSprite(pos.x, pos.y, s, chroma);
	}
	void drawSprite(const VecI2& pos, const RectI& srcRect, const Surface& s, Color chroma = Colors::Magenta)
	{
		drawSprite(pos.x, pos.y, srcRect, s, chroma);
	}
	void drawSprite(const VecI2& pos, RectI srcRect, const RectI& clip, const Surface& s, Color chroma = Colors::Magenta)
	{
		drawSprite(pos.x, pos.y, srcRect, clip, s, chroma);
	}
	~Graphics();
private:
	Microsoft::WRL::ComPtr<IDXGISwapChain>				pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device>				pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			pImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		pRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				pSysBufferTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	pSysBufferTextureView;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>			pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>			pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>				pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>			pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			pSamplerState;
	D3D11_MAPPED_SUBRESOURCE							mappedSysBufferTexture;
	Color* pSysBuffer = nullptr;
public:
	//static constexpr int ScreenWidth = 1920;
	//static constexpr int ScreenHeight = 1080;
	static constexpr int ScreenWidth = 1024;
	static constexpr int ScreenHeight = 720;
	static RectI getScreenRect();
};