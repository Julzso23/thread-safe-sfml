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

#include <SFML/Graphics/Transformable.hpp>
#include <mutex>

namespace tsf
{
    class Transformable : public sf::Transformable
    {
        private:
            mutable std::mutex mutex;
        public:
            void setPosition(float x, float y)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::setPosition(x, y);
            }

            void setPosition(const sf::Vector2f& position)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::setPosition(position);
            }

            void setRotation(float angle)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::setRotation(angle);
            }

            void setScale(float factorX, float factorY)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::setScale(factorX, factorY);
            }

            void setScale(const sf::Vector2f& factors)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::setScale(factors);
            }

            void setOrigin(float x, float y)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::setOrigin(x, y);
            }

            void setOrigin(const sf::Vector2f& origin)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::setOrigin(origin);
            }

            const sf::Vector2f& getPosition() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Transformable::getPosition();
            }

            float getRotation() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Transformable::getRotation();
            }

            const sf::Vector2f& getScale() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Transformable::getScale();
            }

            const sf::Vector2f& getOrigin() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Transformable::getOrigin();
            }

            void move(float offsetX, float offsetY)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::move(offsetX, offsetY);
            }

            void move(const sf::Vector2f& offset)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::move(offset);
            }

            void rotate(float angle)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::rotate(angle);
            }

            void scale(float factorX, float factorY)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::scale(factorX, factorY);
            }

            void scale(const sf::Vector2f& factor)
            {
                std::lock_guard<std::mutex> lock(mutex);
                sf::Transformable::scale(factor);
            }

            const sf::Transform& getTransform() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Transformable::getTransform();
            }

            const sf::Transform& getInverseTransform() const
            {
                std::lock_guard<std::mutex> lock(mutex);
                return sf::Transformable::getInverseTransform();
            }
    };
}
