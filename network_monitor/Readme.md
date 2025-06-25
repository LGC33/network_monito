# Network Connection Monitor

A comprehensive C++ project demonstrating core programming concepts including abstract classes, virtual destructors, deep copy semantics, C-string handling, IP address validation, and professional build systems.

## 🎯 Concepts Demonstrated

### Core C++ Features
- **Abstract Classes**: `NetworkConnection` base class with pure virtual functions
- **Virtual Destructors**: Proper cleanup in inheritance hierarchies  
- **Deep Copy**: Custom copy constructors and assignment operators
- **Reference Usage**: Ampersand (`&`) for aliases and address-of operations
- **C-strings**: Manual memory management with `char*` arrays

### System Programming
- **IP Address Validation**: IPv4/IPv6 validation using `inet_pton()`
- **Socket Programming**: Network connection abstractions
- **System Calls**: Host information and process details

### Build System
- **g++ Compilation**: Multi-file compilation with proper flags
- **Makefile**: Automated build system with multiple targets
- **Git Workflow**: Version control best practices

## 🏗️ Project Structure

```
network_monitor/
├── main.cpp           # Application entry point
├── network.h          # Network classes header
├── network.cpp        # Network classes implementation  
├── utils.h            # Utility functions header
├── utils.cpp          # Utility functions implementation
├── Makefile           # Build system configuration
├── README.md          # This file
├── .gitignore         # Git ignore rules
└── docs/              # Generated documentation (optional)
```

## 🚀 Quick Start

### Prerequisites
- **Compiler**: g++ with C++17 support
- **Build Tools**: make
- **Optional**: valgrind, cppcheck, doxygen, clang-format

### Build and Run
```bash
# Clone and setup
git clone <your-repo-url>
cd network_monitor

# Build the project
make

# Run the application
./network_monitor

# Or build and run in one command
make run
```

## 🔧 Build Targets

### Basic Build Commands
```bash
make            # Build the project (default)
make run        # Build and run
make clean      # Remove build files
make help       # Show all available targets
```

### Build Variants
```bash
make debug      # Debug build with symbols
make release    # Optimized release build
make profile    # Profiling-enabled build
```

### Testing and Analysis
```bash
make test       # Run basic functionality tests
make memtest    # Memory leak testing (requires valgrind)
make check      # Static code analysis (requires cppcheck)
make format     # Code formatting (requires clang-format)
```

### Advanced Targets
```bash
make install    # Install to system (requires sudo)
make dist       # Create source distribution
make docs       # Generate documentation (requires doxygen)
```

## 📖 Usage Examples

### Interactive Menu
The application provides an interactive menu with these options:

1. **Add TCP Connection** - Create a TCP connection object
2. **Add UDP Connection** - Create a UDP connection object  
3. **Show All Connections** - Display configured connections
4. **Test Connection** - Simulate connection testing
5. **Validate IP Address** - Check IP address format and type
6. **Show Statistics** - Display connection statistics
7. **Deep Copy Demo** - Demonstrate deep copy semantics

### Example Session
```
=== Network Connection Monitor ===
1. Add TCP Connection
Enter IP address: 192.168.1.100
Enter port: 8080
TCP connection added successfully!

2. Add UDP Connection  
Enter IP address: 8.8.8.8
Enter port: 53
UDP connection added successfully!

3. Show All Connections
[1] TCP Connection [192.168.1.100:8080] Status: Disconnected
[2] UDP Connection [8.8.8.8:53] Status: Closed
```

## 🔍 Code Highlights

### Abstract Base Class with Virtual Destructor
```cpp
class NetworkConnection {
public:
    virtual void connect() = 0;           // Pure virtual
    virtual void disconnect() = 0;        // Pure virtual
    virtual ~NetworkConnection();         // Virtual destructor
    
    // Deep copy support
    NetworkConnection(const NetworkConnection& other);
    NetworkConnection& operator=(const NetworkConnection& other);
};
```

### Deep Copy Implementation
```cpp
ConnectionHistory::ConnectionHistory(const ConnectionHistory& other) {
    // Deep copy each connection based on actual type
    for (int i = 0; i < count; i++) {
        TCPConnection* tcp = dynamic_cast<TCPConnection*>(other.connections[i]);
        if (tcp) {
            connections[i] = new TCPConnection(*tcp);  // Deep copy
        }
    }
}
```

### IP Address Validation
```cpp
bool isValidIPv4(const char* ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}
```

### Reference Usage Examples
```cpp
void setConnectionStatus(const bool& status) { isConnected = status; }
bool extractIPAndPort(const char* input, char* ip, int& port);
void processIPString(const char* input, char* output, const int& maxSize);
```

## 🛠️ Development

### Git Workflow
```bash
# Initialize repository
git init
git add .
git commit -m "Initial commit: Network Monitor implementation"

# Create feature branch
git checkout -b feature/enhanced-logging
# ... make changes ...
git add .
git commit -m "Add enhanced connection logging"

# Merge back to main
git checkout main
git merge feature/enhanced-logging
```

### Adding New Connection Types
1. Inherit from `NetworkConnection`
2. Implement all pure virtual functions
3. Add virtual destructor
4. Update `ConnectionHistory` deep copy logic
5. Add to factory pattern in main menu

### Memory Management Notes
- All C-strings use manual allocation (`new char[]` / `delete[]`)
- Virtual destructors ensure proper cleanup
- Deep copy prevents double-deletion errors
- RAII principles followed throughout

## 🧪 Testing

### Manual Testing
```bash
make test                    # Run automated tests
echo "192.168.1.1" | make run  # Pipe input for testing
```

### Memory Testing
```bash
make memtest                 # Run with valgrind
# Should show no memory leaks if properly implemented
```

### Code Quality
```bash
make check                   # Static analysis
make format                  # Code formatting
```

## 📚 Learning Objectives

This project teaches:

1. **Object-Oriented Design**: Abstract classes, inheritance, polymorphism
2. **Memory Management**: Deep copy, virtual destructors, RAII
3. **System Programming**: Network APIs, IP validation, system calls
4. **Build Systems**: Makefiles, compilation process, dependency management
5. **Version Control**: Git workflow, branching, merging
6. **Code Quality**: Static analysis, memory checking, documentation

## 🔗 References

- [C++ Reference](https://cppreference.com/)
- [Make Manual](https://www.gnu.org/software/make/manual/)
- [Git Documentation](https://git-scm.com/doc)
- [Socket Programming Guide](https://beej.us/guide/bgnet/)

## 📄 License

This project is for educational purposes. Feel free to use and modify.

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Ensure all tests pass
6. Submit a pull request

---

**Note**: This project demonstrates C++ concepts in a practical context. It's designed for learning and may not be suitable for production network monitoring without additional security and error handling.