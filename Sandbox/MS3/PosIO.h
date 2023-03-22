#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>

namespace sdds {
	class PosIO {
	public:
		virtual std::ostream& write(std::ostream&) const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual std::ofstream& save(std::ofstream&) const = 0;
		virtual std::ifstream& load(std::ifstream&) = 0;
		virtual ~PosIO() = default;
	};
	std::ostream& operator <<(std::ostream&, const PosIO& Ro);
	std::ofstream& operator <<(std::ofstream&, const PosIO& Ro);
	std::istream& operator >>(std::istream&, PosIO& Ro);
	std::ifstream& operator >>(std::ifstream&, PosIO& Ro);
}

#endif 