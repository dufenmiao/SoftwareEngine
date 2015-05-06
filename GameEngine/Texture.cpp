#include "pch.h"
#include "Texture.h"

#include "Robuffer.h"

using namespace GameEngine;
using namespace concurrency;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Platform;

Texture::Texture()
{

}

Texture::Texture(int width, int height) : m_width(width), m_height(height), m_buffer(nullptr)
{

}

task<void> Texture::Load(String^ filename)
{
	return create_task(Windows::ApplicationModel::Package::Current->InstalledLocation->GetFileAsync(filename))
		.then([](StorageFile^ file){
		return file->OpenAsync(FileAccessMode::Read);
	}).then([ this](IRandomAccessStream^ stream){
		
		WriteableBitmap^ bitmap = ref new WriteableBitmap(m_width, m_height);
		bitmap->SetSource(stream);

		// Query the IBufferByteAccess interface.
		Microsoft::WRL::ComPtr<IBufferByteAccess> bufferByteAccess;
		reinterpret_cast<IInspectable*>(bitmap->PixelBuffer)->QueryInterface(IID_PPV_ARGS(&bufferByteAccess));

		// Retrieve the buffer data.
		byte* buffer = nullptr;
		HRESULT hr = bufferByteAccess->Buffer(&buffer);
		if (FAILED(hr))
		{
			throw Exception::CreateException(hr);
		}
		m_buffer = buffer;
	}).then([](task<void> t){
		try
		{
			t.get();
		}
		catch (Exception^ e)
		{

		}
	});
}

Color Texture::Map(float u, float v)
{
	if (m_buffer == nullptr)
	{
		return Color();
	}
	unsigned int iu = std::abs(static_cast<int>(u * m_width) % m_width);
	unsigned int iv = std::abs(static_cast<int>(v * m_height) % m_height);

	int pos = static_cast<int>(u + v * m_width) * 4;

	byte B = m_buffer[pos];
	byte G = m_buffer[pos + 1];
	byte R = m_buffer[pos + 2];
	byte A = m_buffer[pos + 3];

	return Color(R / 255.f, G / 255.f, B / 255.f, A / 255.f);
	
}