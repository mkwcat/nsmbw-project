set(xml_out_file "${CMAKE_BINARY_DIR}/riivolution/mkwcat-nsmbw.xml")
set(xml_in_file "${CMAKE_SOURCE_DIR}/riivolution/mkwcat-nsmbw.xml")

add_custom_command(
    OUTPUT "${xml_out_file}"
    DEPENDS loader "${xml_in_file}" "${INSERTXML}"
    COMMENT "Generating mkwcat-nsmbw.xml"
    COMMAND python ${INSERTXML} "${xml_in_file}" "${CMAKE_BINARY_DIR}/loader/loader.elf" "${xml_out_file}"
)

add_custom_target(mkwcat_nsmbw_xml
    ALL
    DEPENDS "${xml_out_file}"
)
