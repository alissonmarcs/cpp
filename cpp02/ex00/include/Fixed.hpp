#pragma once

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &object);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int						integer;
		const static int		decimal = 8;
};
