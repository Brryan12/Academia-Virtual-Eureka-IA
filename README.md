# Proyecto_2_Progra_1
- [PDF con las instrucciones del proyecto](./proyecto2.pdf)
# Academic Management System  

**A C++ program for managing students, professors, courses, and groups using OOP principles.**  

## Key Features  
- **Student/Professor Management**: Store personal data and academic information  
- **Course Enrollment**: Handle course registration with schedule validation  
- **Group Management**: Organize students into class groups  
- **Invoice Generation**: Automatic calculation of fees with discounts  
- **Data Persistence**: Save all records to text files  

## Technical Implementation  
- **Custom Linked List** for data storage  
- **Inheritance Hierarchy**: `Person` → `Student`/`Professor`  
- **File I/O System**: Binary/text file operations  
- **Input Validation**: Prevents duplicates and invalid entries  

## SOLID Principles Applied  
1. **Single Responsibility**: Each class handles one logical component  
2. **Open/Closed**: Extensible for new academic entities  
3. **Liskov Substitution**: Child classes properly extend `Person`  
4. **Interface Segregation**: Focused method sets per class  
5. **Dependency Inversion**: High-level modules depend on abstractions  

## Development Notes  
- Requires C++17 or later  
- Tested on Windows/Linux with GCC/Clang  
- Includes comprehensive error handling
