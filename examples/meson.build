project_test_files += files('addition.cc')

executable('addition',
           ['addition.cc'],
           include_directories : public_header_files,
           link_with : [project_target],
           dependencies: [tatl],
           cpp_args : project_build_args)
