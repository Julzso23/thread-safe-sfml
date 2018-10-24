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

#include <SFML/Graphics/Sprite.hpp>
#include <mutex>

namespace tsf
{
    class Sprite : public sf::Sprite
    {
        private:
            mutable std::mutex mutex;
        public:
            Sprite() : sf::Sprite() {}

            explicit Sprite(const sf::Texture& texture) : sf::Sprite(texture) {}

            Sprite(const sf::Texture& texture, const sf::IntRect& rectangle) : sf::Sprite(texture, rectangle) {}

            void setTexture(const sf::Texture& texture, bool resetRect = false)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Sprite::setTexture(texture, resetRect);
            }

            void setTextureRect(const sf::IntRect& rectangle)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Sprite::setTextureRect(rectangle);
            }

            void setColor(const sf::Color& color)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Sprite::setColor(color);
            }

            const sf::Texture* getTexture() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Sprite::getTexture();
            }

            const sf::IntRect& getTextureRect() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Sprite::getTextureRect();
            }

            const sf::Color& getColor() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Sprite::getColor();
            }

            sf::FloatRect getLocalBounds() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Sprite::getLocalBounds();
            }

            sf::FloatRect getGlobalBounds() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Sprite::getGlobalBounds();
            }
    };
}
