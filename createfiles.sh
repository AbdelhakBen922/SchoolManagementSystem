#!/bin/bash

# List of class names
classes=(
    "Schedule"
    "Profile"
    "Teacher"
    "Place"
    "Student"
    "Course"
    "Exam"
    "Group"
    "SCourse"
    "Year"
    "Section"
    "Semestre"
    "Date"
    "Time"
    "Administrator"
    "School"
    "Slide"
    "Session"
)

# Function to create .h and .cpp files with basic class structure
create_files() {
    for class in "${classes[@]}"; do
        header_file="${class}.h"
        source_file="${class}.cpp"

        # Create header file
        if [ ! -f "$header_file" ]; then
            echo "#ifndef ${class}_H" > "$header_file"
            echo "#define ${class}_H" >> "$header_file"
            echo "" >> "$header_file"
            echo "class ${class} {" >> "$header_file"
            echo "public:" >> "$header_file"
            echo "    ${class}();" >> "$header_file"
            echo "    ~${class}();" >> "$header_file"
            echo "};" >> "$header_file"
            echo "" >> "$header_file"
            echo "#endif // ${class}_H" >> "$header_file"
            echo "Created ${header_file}"
        else
            echo "${header_file} already exists, skipping."
        fi

        # Create source file
        if [ ! -f "$source_file" ]; then
            echo "#include \"${header_file}\"" > "$source_file"
            echo "" >> "$source_file"
            echo "${class}::${class}() {" >> "$source_file"
            echo "    // Constructor implementation" >> "$source_file"
            echo "}" >> "$source_file"
            echo "" >> "$source_file"
            echo "${class}::~${class}() {" >> "$source_file"
            echo "    // Destructor implementation" >> "$source_file"
            echo "}" >> "$source_file"
            echo "Created ${source_file}"
        else
            echo "${source_file} already exists, skipping."
        fi
    done
}

# Run the function to create the files
create_files
