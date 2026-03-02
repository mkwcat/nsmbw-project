ENTRY(_prolog)

SECTIONS {
	.text : {
		KEEP(*(rel_prolog))
		*(.text*)
		KEEP(*(replaced))
		KEEP(*(extern))
	}

	.data : {
        . = ALIGN(4);
        _MRel_replace_array = .;
        KEEP(*(replace_array))
        _MRel_replace_array_end = .;

        . = ALIGN(4);
        _MRel_patch_references_array = .;
        KEEP(*(patch_references_array))
        _MRel_patch_references_array_end = .;

        . = ALIGN(4);
        _MRel_extern_array = .;
        KEEP(*(extern_array))
        _MRel_extern_array_end = .;

        *(.rodata*)

        . = ALIGN(4);
		*(.data*)
		*(.sdata*)
		*(.sdata2*)

		. = ALIGN(4);
		_ctors = .;
		*(.ctors)
		*(.init_array)
		_ctors_end = .;
	}

	.bss : {
		*(.bss*)
		*(.sbss*)
	}

    /DISCARD/ : {
        *(.eh_frame*)
    }
}
