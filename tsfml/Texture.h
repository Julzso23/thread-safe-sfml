#pragma once

/*
MIT License

Copyright (c) 2018 Julian Bath

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <SFML/Graphics/Texture.hpp>
#include <mutex>

namespace tsf
{
    class Texture : public sf::Texture
    {
        private:
            mutable std::mutex mutex;
        public:
            Texture() : sf::Texture() {}
            Texture(const sf::Texture& copy) : sf::Texture(copy) {}
            bool create(unsigned int width, unsigned int height)
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::create(width, height);
            }

            bool loadFromFile(const std::string& filename, const sf::IntRect& area = sf::IntRect())
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::loadFromFile(filename, area);
            }

            bool loadFromMemory(const void* data, std::size_t size, const sf::IntRect& area = sf::IntRect())
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::loadFromMemory(data, size, area);
            }

            bool loadFromStream(sf::InputStream& stream, const sf::IntRect& area = sf::IntRect())
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::loadFromStream(stream, area);
            }

            bool loadFromImage(const sf::Image& image, const sf::IntRect& area = sf::IntRect())
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::loadFromImage(image, area);
            }

            sf::Vector2u getSize() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::getSize();
            }

            sf::Image copyToImage() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::copyToImage();
            }

            void update(const sf::Uint8* pixels)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::update(pixels);
            }

            void update(const sf::Uint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::update(pixels, width, height, x, y);
            }

            void update(const sf::Texture& texture)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::update(texture);
            }

            void update(const sf::Texture& texture, unsigned int x, unsigned int y)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::update(texture, x, y);
            }

            void update(const sf::Image& image)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::update(image);
            }

            void update(const sf::Image& image, unsigned int x, unsigned int y)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::update(image, x, y);
            }

            void update(const sf::Window& window)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::update(window);
            }

            void update(const sf::Window& window, unsigned int x, unsigned int y)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::update(window, x, y);
            }

            void setSmooth(bool smooth)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::setSmooth(smooth);
            }

            bool isSmooth() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::isSmooth();
            }

            void setSrgb(bool sRgb)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::setSrgb(sRgb);
            }

            bool isSrgb() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::isSrgb();
            }

            void setRepeated(bool repeated)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::setRepeated(repeated);
            }

            bool isRepeated() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::isRepeated();
            }

            bool generateMipmap()
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::generateMipmap();
            }

            sf::Texture& operator =(const sf::Texture& right)
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::operator=(right);
            }

            void swap(sf::Texture& right)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Texture::swap(right);
            }

            unsigned int getNativeHandle() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Texture::getNativeHandle();
            }
    };
}
