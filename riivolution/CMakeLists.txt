add_custom_target(mkwcat-nsmbw.xml
    ALL
    DEPENDS loader "${CMAKE_SOURCE_DIR}/riivolution/mkwcat-nsmbw.xml" "${INSERTXML}"
    COMMENT "Generating mkwcat-nsmbw.xml"
    COMMAND python ${INSERTXML} "${CMAKE_SOURCE_DIR}/riivolution/mkwcat-nsmbw.xml" "${CMAKE_BINARY_DIR}/loader/loader.elf" "${CMAKE_BINARY_DIR}/riivolution/mkwcat-nsmbw.xml"
)
