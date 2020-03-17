#include "console_log_stream.hpp"

#include <stdio.h>

namespace nova {
    StdoutStream::StdoutStream() : rx::stream(k_flush | k_write) {}

    rx_u64 StdoutStream::on_write(const rx_byte* data, const rx_u64 size) { return fwrite(data, size, 1, stdout); }

    bool StdoutStream::on_flush() {
        fflush(stdout);
        return true;
    }

    const rx::string& StdoutStream::name() const& { return my_name; }
} // namespace nova
