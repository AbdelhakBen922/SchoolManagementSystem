#!/bin/bash

# Read the input file
input_file="../SchoolManagementSystem.h"  # Change this to the name of your input file
classes=()
current_class=""
class_content=""

while IFS= read -r line; do
    if [[ "$line" =~ ^class[[:space:]]+([[:alnum:]]+) ]]; then
        if [[ -n "$current_class" ]]; then
            include_directives="#include <iostream>"  # Default include for all classes
            include_directives+=$(echo -e "$class_content" | grep -oE '#include[[:space:]]+<.*>')
            include_directives+=$(echo -e "$class_content" | grep -oE '#include[[:space:]]+".*"')
            echo -e "#pragma once\n${include_directives}\n\nclass ${current_class} {\npublic:\n${class_content}\n};" > "${current_class}.h"
            echo -e "#include \"${current_class}.h\"\n\n${class_content}" > "${current_class}.cpp"
            echo "Created ${current_class}.h and ${current_class}.cpp"
        fi
        current_class="${BASH_REMATCH[1]}"
        class_content=""
    else
        class_content+="$line\n"
    fi
done < "$input_file"

# Process the last class
if [[ -n "$current_class" ]]; then
    include_directives="#include <iostream>"  # Default include for all classes
    include_directives+=$(echo -e "$class_content" | grep -oE '#include[[:space:]]+<.*>')
    include_directives+=$(echo -e "$class_content" | grep -oE '#include[[:space:]]+".*"')
    echo -e "#pragma once\n${include_directives}\n\nclass ${current_class} {\npublic:\n${class_content}\n};" > "${current_class}.h"
    echo -e "#include \"${current_class}.h\"\n\n${class_content}" > "${current_class}.cpp"
    echo "Created ${current_class}.h and ${current_class}.cpp"
fi
